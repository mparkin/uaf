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

#ifndef UAFC_SESSION_H_
#define UAFC_SESSION_H_


// STD
#include <string>
#include <sstream>
// SDK
#include "uaclient/uaclientsdk.h"
#include "uaclient/uasession.h"
#include "uabase/uastring.h"
#include "uapki/uapkicertificate.h"
// UAF
#include "uaf/util/status.h"
#include "uaf/util/logger.h"
#include "uaf/util/serverarray.h"
#include "uaf/util/namespacearray.h"
#include "uaf/util/nodeid.h"
#include "uaf/util/browsepath.h"
#include "uaf/util/helperfunctions.h"
#include "uaf/client/clientexport.h"
#include "uaf/client/sessions/sessionstates.h"
#include "uaf/client/sessions/sessioninformation.h"
#include "uaf/client/settings/sessionsettings.h"
#include "uaf/client/subscriptions/subscriptionfactory.h"
#include "uaf/client/discovery/discoverer.h"
#include "uaf/client/clientservices.h"





namespace uafc
{


    /*******************************************************************************************//**
    * An uafc::Session wraps the Session object of the SDK and adds some functionality.
    *
    * @ingroup ClientSessions
    ***********************************************************************************************/
    class UAFC_EXPORT Session
    {
    public:


        /**
         * Construct a session.
         *
         * @param loggerFactory      Logger factory to log all messages to.
         * @param sessionSettings    Settings of the session.
         * @param serverUri          Server URI of the session.
         * @param clientConnectionId Id of the connection.
         * @param uaSessionCallback  Callback interface of the session.
         * @param clientInterface    Client interface to call when asynchronous
         *                           communication is received.
         * @param discoverer         The discoverer of the client.
         * @param database           Pointer to the client database.
         */
        Session(
                uaf::LoggerFactory*             loggerFactory,
                const uafc::SessionSettings&    sessionSettings,
                const std::string&              serverUri,
                uaf::ClientConnectionId         clientConnectionId,
                UaClientSdk::UaSessionCallback* uaSessionCallback,
                uafc::ClientInterface*          clientInterface,
                uafc::Discoverer*               discoverer,
                uafc::Database*                 database);


        /**
         * Destruct the session.
         */
        virtual ~Session();


        ////////////////////////////////////////////////////////////////////////////////////////////
        /**
         *  @name Connection
         *  Connect and disconnect the session.
         */
        ///@{

        /**
         * Connect the session.
         */
        uaf::Status connect();


        /**
         * Disconnect the session.
         *
         * @return  Good if the session could be disconnected successfully, bad if not.
         */
        uaf::Status disconnect();


        ///@} //////////////////////////////////////////////////////////////////////////////////////
        /**
         *  @name SessionInfo
         *  Get information about the session.
         */
        ///@{


        /**
         * Check if the session is created on the server side.
         *
         * @return  True if the session is established, False if not.
         */
        bool isConnected() const;


        /**
         * Get information about the session.
         *
         * @return  The information.
         */
        uafc::SessionInformation sessionInformation() const;


        /**
         * Get the client connection id of the session.
         */
        uaf::ClientConnectionId clientConnectionId()        const { return clientConnectionId_; };

        /**
         * Get the server URI of the session.
         */
        std::string serverUri()                             const { return serverUri_; };

        /**
         * Get the settings of the session.
         */
        uafc::SessionSettings sessionSettings()             const { return sessionSettings_; };

        /**
         * Get the state of the session.
         */
        uafc::sessionstates::SessionState sessionState()    const { return sessionState_; };


        ///@} //////////////////////////////////////////////////////////////////////////////////////
        /**
         *  @name Subscriptions
         *  Subscribe, unsubscribe, and get information about subscriptions.
         */
        ///@{

        /**
         * Manually create a subscription.
         *
         * For more info about "manual" methods, see the documentation on the
         * uafc::Client::manuallyConnect method.
         *
         * @param settings              The settings of the subscription you'd like to create.
         * @param clientSubscriptionHandle  Output parameter, giving you the handle of the newly
         *                                  created subscription.
         * @return                      Good if the subscription was successfully created, Bad if
         *                              something went wrong.
         */
        uaf::Status manuallySubscribe(
                const uafc::SubscriptionSettings&   settings,
                uaf::ClientSubscriptionHandle&      clientSubscriptionHandle);


        /**
         * Manually delete a subscription.
         *
         * @param clientSubscriptionHandle  The handle of the subscription.
         * @return                          Good if the subscription could be deleted, bad if there
         *                                  was some problem.
         */
        uaf::Status manuallyUnsubscribe(uaf::ClientSubscriptionHandle clientSubscriptionHandle);


        /**
         * Get information about a particular subscription.
         *
         * @param clientSubscriptionHandle  The handle identifying the subscription.
         * @param subscriptionInformation   Output parameter, giving you the information about the
         *                                  subscription.
         * @return                          Good if the subscription could be found, Bad if not.
         */
        uaf::Status subscriptionInformation(
                 uaf::ClientSubscriptionHandle      clientSubscriptionHandle,
                 uafc::SubscriptionInformation&     subscriptionInformation);


        /**
        * Get some information about the specified monitored item.
        *
        * @param clientHandle               The handle identifying the monitored item.
        * @param monitoredItemInformation   Output parameter: the requested information.
        * @return                           True if the monitored item was found, False if not.
        */
        bool monitoredItemInformation(
                uaf::ClientHandle               clientHandle,
                uafc::MonitoredItemInformation& monitoredItemInformation);

        /**
         * Get information about all subscriptions.
         *
         * @return  A vector of all available SubscriptionInformation.
         */
        std::vector<uafc::SubscriptionInformation> allSubscriptionInformations();


        /**
         * Set the publishing mode of a particular subscription.
         *
         * @param clientSubscriptionHandle  The handle identifying the subscription.
         * @param publishingEnabled         True to enable the subscription, false if not.
         * @param serviceSettings           The service settings to be used.
         * @param subscriptionFound         Output parameter, True if the subscription specified
         *                                  by the clientSubscriptionHandle was found, False if not.
         * @return                          Result of the service call.
         */
        uaf::Status setPublishingMode(
                uaf::ClientSubscriptionHandle  clientSubscriptionHandle,
                bool                           publishingEnabled,
                const uafc::ServiceSettings&   serviceSettings,
                bool&                          subscriptionFound);



        ///@} //////////////////////////////////////////////////////////////////////////////////////
        /**
         *  @name ServiceInvocations
         *  Invoke a service within this session.
         */
        ///@{

        /**
         * Invoke the Session service at this level (the Session level).
         *
         * @param request       The SessionRequest corresponding with the invocation.
         * @param invocation    The invocation.
         */
        template<typename _Service>
        uaf::Status invokeService(
                const uafc::BaseSessionRequest<typename _Service::Config,
                                               typename _Service::RequestTarget,
                                               _Service::asynchronous>& request,
                typename _Service::Invocation& invocation)
        {
            return invocation.invoke(uaSession_, namespaceArray_, serverArray_, logger_);
        }



        /**
         * Invoke the Subscription service at this level (the Subscription level).
         *
         * @param request       The SubscriptionRequest corresponding with the invocation.
         * @param invocation    The invocation.
         */
        template<typename _Service>
        uaf::Status invokeService(
                const uafc::BaseSubscriptionRequest<typename _Service::Config,
                                                    typename _Service::RequestTarget,
                                                    _Service::asynchronous>& request,
                typename _Service::Invocation& invocation)
        {
            return subscriptionFactory_->invokeService<_Service>(
                    invocation,
                    namespaceArray_,
                    serverArray_);
        }


        ///@} //////////////////////////////////////////////////////////////////////////////////////
        /**
         *  @name Misc.
         *  Miscellaneous methods.
         */
        ///@{


        /**
         * Get a compact string representation of the Session.
         *
         * @return  Compact string representation.
         */
        std::string toString() const;


        /**
         * Change the state of the session.
         *
         * @param sessionState     The new state.
         */
        void setSessionState(uafc::sessionstates::SessionState sessionState);


        ///@}

    private:


        DISALLOW_COPY_AND_ASSIGN(Session);


        /**
         * Update the ServerArray and NamespaceArray (not locked!).
         *
         * @return  Good if the arrays could be fetched, false if not.
         */
        uaf::Status updateArrays();


        /**
         * Update the connection info.
         */
        void updateConnectionInfo(uaf::ClientConnectionId clientConnectionId);


        // Wrapped SDK session instance and callback instance
        UaClientSdk::UaSession*             uaSession_;
        UaClientSdk::UaSessionCallback*     uaSessionCallback_;

        // server and namespace arrays
        uaf::ServerArray                    serverArray_;
        uaf::NamespaceArray                 namespaceArray_;

        // the current session state:
        uafc::sessionstates::SessionState   sessionState_;

        // fixed session properties:
        uaf::ClientConnectionId             clientConnectionId_;
        std::string                         serverUri_;
        uafc::SessionSettings               sessionSettings_;

        // the logger of the session
        uaf::Logger*                        logger_;
        // pointer to the client databse
        uafc::Database*                     database_;
        // the subscription factory of this session
        uafc::SubscriptionFactory*          subscriptionFactory_;
        // the SessionConnectInfo
        UaClientSdk::SessionConnectInfo     uaSessionConnectInfo_;
        // mutex for critical sections
        UaMutex                             sessionMutex_;
        // the RequesterInterface to call when asynchronous messages are received
        uafc::ClientInterface*              clientInterface_;
        // the Discoverer to use
        uafc::Discoverer*                   discoverer_;


    };


}


#endif /* UAFC_SESSION_H_ */
