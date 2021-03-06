/* This file is part of the UAF (Unified Architecture Framework) project.
 *
 * Copyright (C) 2012 Wim Pessemier (Institute of Astronomy, KULeuven)
 *
 * Project website: http://www.ster.kuleuven.be/uaf
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "uaf/client/invocations/methodcallinvocation.h"

namespace uafc
{
    using namespace uaf;
    using namespace uafc;
    using std::string;
    using std::stringstream;
    using std::vector;


    // Fill the synchronous SDK members
    // =============================================================================================
    Status MethodCallInvocation::fromSyncUafToSdk(
            const vector<MethodCallRequestTarget>&  targets,
            const MethodCallSettings&               settings,
            const NamespaceArray&                   nameSpaceArray,
            const ServerArray&                      serverArray)
    {
        Status ret;

        // update the uaServiceSettings_
        ret = settings.toSdk(uaServiceSettings_);

        // declare the number of targets
        size_t noOfTargets = targets.size();

        // resize the number of uaReadValueIds_
        uaCallMethodRequests_.create(noOfTargets);

        // loop through the targets
        for (size_t i = 0; i < noOfTargets && ret.isGood(); i++)
        {
            // update the object node id of the target
            ret = nameSpaceArray.fillOpcUaNodeId(
                    targets[i].objectAddress,
                    uaCallMethodRequests_[i].ObjectId);

            // update the method node id of the target
            if (ret.isGood())
                // update the object node id of the target
                ret = nameSpaceArray.fillOpcUaNodeId(
                        targets[i].methodAddress,
                        uaCallMethodRequests_[i].MethodId);

            // only update the rest of the SDK variables if no error has occurred yet
            if (ret.isGood())
            {
                // declare the number of input arguments
                size_t noOfInputArguments = targets[i].inputArguments.size();

                // fill the SDK input arguments
                uaCallMethodRequests_[i].NoOfInputArguments = noOfInputArguments;
                uaCallMethodRequests_[i].InputArguments = new OpcUa_Variant[noOfInputArguments];
                for (size_t j = 0; j < noOfInputArguments; j++)
                    targets[i].inputArguments[j].toSdk(
                            &uaCallMethodRequests_[i].InputArguments[j]);
            }
        }

        return ret;
    }


    // Fill asynchronous the SDK members
    // =============================================================================================
    Status MethodCallInvocation::fromAsyncUafToSdk(
            const vector<MethodCallRequestTarget>&  targets,
            const MethodCallSettings&               settings,
            const NamespaceArray&                   nameSpaceArray,
            const ServerArray&                      serverArray)
    {
        Status ret;

        // update the uaServiceSettings_
        ret = settings.toSdk(uaServiceSettings_);

        // declare the number of targets
        size_t noOfTargets = targets.size();

        if (targets.size() != 1)
            ret.setStatus(statuscodes::UnsupportedError,
                          "The SDK does not support asynchronous calling of multiple methods "
                          "at once");
        else
            ret.setGood();

        // loop through the targets
        for (size_t i = 0; i < noOfTargets && ret.isGood(); i++)
        {
            // update the object node id of the target
            OpcUa_NodeId objectId;
            ret = nameSpaceArray.fillOpcUaNodeId(targets[i].objectAddress, objectId);
            uaCallIn_.objectId = objectId;

            // update the method node id of the target
            if (ret.isGood())
            {
                OpcUa_NodeId methodId;
                ret = nameSpaceArray.fillOpcUaNodeId(targets[i].methodAddress, methodId);
                uaCallIn_.methodId = methodId;
            }

            // only update the rest of the SDK variables if no error has occurred yet
            if (ret.isGood())
            {
                // declare the number of input arguments
                size_t noOfInputArguments = targets[i].inputArguments.size();

                // fill the SDK input arguments
                uaCallIn_.inputArguments.create(noOfInputArguments);
                for (size_t j = 0; j < noOfInputArguments; j++)
                    targets[i].inputArguments[j].toSdk(
                            &uaCallIn_.inputArguments[j]);
            }
        }

        return ret;
    }



    // Invoke the service synchronously
    // =============================================================================================
    Status MethodCallInvocation::invokeSyncSdkService(UaClientSdk::UaSession* uaSession)
    {
        Status ret;

        UaStatus uaStatus = uaSession->callList(
                    uaServiceSettings_,
                    uaCallMethodRequests_,
                    uaCallMethodResults_,
                    uaDiagnosticInfos_);
        ret.fromSdk(uaStatus.statusCode(),
                               "Synchronous method call invocation failed");

        return ret;
    }



    // Invoke the service asynchronously
    // =============================================================================================
    Status MethodCallInvocation::invokeAsyncSdkService(
            UaClientSdk::UaSession* uaSession,
            TransactionId           transactionId)
    {
        Status ret;

        UaStatus uaStatus = uaSession->beginCall(uaServiceSettings_, uaCallIn_, transactionId);

        ret.fromSdk(uaStatus.statusCode(), "Asynchronous method call invocation failed");

        return ret;
    }



    // Fill the UAF members
    // =============================================================================================
    Status MethodCallInvocation::fromSyncSdkToUaf(
            const NamespaceArray&           nameSpaceArray,
            const ServerArray&              serverArray,
            vector<MethodCallResultTarget>& targets)
    {
        // declare the return Status
        Status ret;

        // declare the number of targets and resize the output parameter accordingly
        uint32_t noOfTargets = uaCallMethodRequests_.length();
        targets.resize(noOfTargets);

        // check the number of targets
        if (noOfTargets == uaCallMethodResults_.length())
        {

            for (uint32_t i = 0; i < noOfTargets ; i++)
            {
                // update the status
                targets[i].status.fromSdk(
                        uaCallMethodResults_[i].StatusCode,
                        "Server reported method call error");

                // get the number of output arguments
                int32_t noOfOutputArguments = uaCallMethodResults_[i].NoOfOutputArguments;

                // resize the outputArguments vector
                targets[i].outputArguments.resize(noOfOutputArguments);

                // fill the outputArguments
                for (int32_t j = 0; j < noOfOutputArguments; j++)
                    targets[i].outputArguments[j] \
                                                 = uaCallMethodResults_[i].OutputArguments[j];

            }

            ret.setGood();
        }
        else
        {
            ret.setStatus(statuscodes::UnexpectedError,
                          "Number of targets does not match number of targets");
        }

        return ret;
    }




}
