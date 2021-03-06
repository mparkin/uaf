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

%module requests
%{
#define SWIG_FILE_WITH_INIT
#include "uaf/util/primitives.h"
#include "uaf/util/referencedescription.h"
#include "uaf/util/modificationinfo.h"
#include "uaf/client/settings/clientsettings.h"
#include "uaf/client/requests/basesessionrequesttarget.h"
#include "uaf/client/requests/basesubscriptionrequesttarget.h"
#include "uaf/client/requests/createmonitoreddatarequesttarget.h"
#include "uaf/client/requests/createmonitoredeventsrequesttarget.h"
#include "uaf/client/requests/methodcallrequesttarget.h"
#include "uaf/client/requests/readrequesttarget.h"
#include "uaf/client/requests/browserequesttarget.h"
#include "uaf/client/requests/browsenextrequesttarget.h"
#include "uaf/client/requests/translatebrowsepathstonodeidsrequesttarget.h"
#include "uaf/client/requests/writerequesttarget.h"
#include "uaf/client/requests/historyreadrawmodifiedrequesttarget.h"
#include "uaf/client/requests/basesessionrequest.h"
#include "uaf/client/requests/basesubscriptionrequest.h"
#include "uaf/client/requests/requests.h"
%}


// include common definitions
%include "../pyuaf.i"


// import the EXPORT macro and some numeric typedefs
%import "uaf/client/clientexport.h"
%import "uaf/util/handles.h"


// import the necessary dependencies from pyuaf.util
%import(module="pyuaf.util.attributeids")       "pyuaf/util/util_attributeids.i"
%import(module="pyuaf.util.monitoringmodes")    "pyuaf/util/util_monitoringmodes.i"
%import(module="pyuaf.util.primitives")         "pyuaf/util/util_primitives.i"
%import(module="pyuaf.util.browsedirections")   "pyuaf/util/util_browsedirections.i"
%import(module="pyuaf.util.nodeclasses")        "pyuaf/util/util_nodeclasses.i"
%import(module="pyuaf.util.timestampstoreturn") "pyuaf/util/util_timestampstoreturn.i"
%import(module="pyuaf.util")                    "uaf/util/stringifiable.h"
%import(module="pyuaf.util")                    "uaf/util/browsepath.h"


// also include the typemap
#if defined(SWIGPYTHON)
    %include "pyuaf/util/util_bytestring_python.i"
    %include "pyuaf/util/util_variant_python.i"
#endif


// also import the wrapped xxxxConfigs classes
%import "pyuaf/client/client_configs.i"


// before including any classes in a generic way, specify the "special treatments" of certain classes:
%ignore getServerUriFromTarget(const BaseSessionRequestTarget& target, std::string& serverUri);
MAKE_NON_DYNAMIC(uafc::CreateMonitoredDataRequestTarget)
MAKE_NON_DYNAMIC(uafc::CreateMonitoredEventsRequestTarget)
MAKE_NON_DYNAMIC(uafc::MethodCallRequestTarget)
MAKE_NON_DYNAMIC(uafc::ReadRequestTarget)
MAKE_NON_DYNAMIC(uafc::TranslateBrowsePathsToNodeIdsRequestTarget)
MAKE_NON_DYNAMIC(uafc::BrowseRequestTarget)
MAKE_NON_DYNAMIC(uafc::BrowseNextRequestTarget)
MAKE_NON_DYNAMIC(uafc::WriteRequestTarget)
MAKE_NON_DYNAMIC(uafc::HistoryReadRawModifiedRequestTarget)
%ignore operator==(const BaseSessionRequest<_ServiceConfig, _Target, _Async>& object1, const BaseSessionRequest<_ServiceConfig, _Target, _Async>& object2);
%ignore operator!=(const BaseSessionRequest<_ServiceConfig, _Target, _Async>& object1, const BaseSessionRequest<_ServiceConfig, _Target, _Async>& object2);
%ignore operator< (const BaseSessionRequest<_ServiceConfig, _Target, _Async>& object1, const BaseSessionRequest<_ServiceConfig, _Target, _Async>& object2);
%ignore operator==(const BaseSubscriptionRequest<_ServiceConfig, _Target, _Async>& object1, const BaseSubscriptionRequest<_ServiceConfig, _Target, _Async>& object2);
%ignore operator!=(const BaseSubscriptionRequest<_ServiceConfig, _Target, _Async>& object1, const BaseSubscriptionRequest<_ServiceConfig, _Target, _Async>& object2);
%ignore operator< (const BaseSubscriptionRequest<_ServiceConfig, _Target, _Async>& object1, const BaseSubscriptionRequest<_ServiceConfig, _Target, _Async>& object2);


// wrap some classes that are not defined by macros:
UAF_WRAP_CLASS("uaf/client/requests/basesessionrequesttarget.h"                  , uafc , BaseSessionRequestTarget                   , COPY_NO , TOSTRING_NO,  COMP_NO,  pyuaf.client.requests, VECTOR_NO)
UAF_WRAP_CLASS("uaf/client/requests/basesubscriptionrequesttarget.h"             , uafc , BaseSubscriptionRequestTarget              , COPY_NO , TOSTRING_NO,  COMP_NO,  pyuaf.client.requests, VECTOR_NO)
UAF_WRAP_CLASS("uaf/client/requests/browserequesttarget.h"                       , uafc , BrowseRequestTarget                        , COPY_YES, TOSTRING_YES, COMP_YES, pyuaf.client.requests, BrowseRequestTargetVector)
UAF_WRAP_CLASS("uaf/client/requests/browsenextrequesttarget.h"                   , uafc , BrowseNextRequestTarget                    , COPY_YES, TOSTRING_YES, COMP_YES, pyuaf.client.requests, BrowseNextRequestTargetVector)
UAF_WRAP_CLASS("uaf/client/requests/createmonitoreddatarequesttarget.h"          , uafc , CreateMonitoredDataRequestTarget           , COPY_YES, TOSTRING_YES, COMP_YES, pyuaf.client.requests, CreateMonitoredDataRequestTargetVector)
UAF_WRAP_CLASS("uaf/client/requests/createmonitoredeventsrequesttarget.h"        , uafc , CreateMonitoredEventsRequestTarget         , COPY_YES, TOSTRING_YES, COMP_YES, pyuaf.client.requests, CreateMonitoredEventsRequestTargetVector)
UAF_WRAP_CLASS("uaf/client/requests/methodcallrequesttarget.h"                   , uafc , MethodCallRequestTarget                    , COPY_YES, TOSTRING_YES, COMP_YES, pyuaf.client.requests, MethodCallRequestTargetVector)
UAF_WRAP_CLASS("uaf/client/requests/readrequesttarget.h"                         , uafc , ReadRequestTarget                          , COPY_YES, TOSTRING_YES, COMP_YES, pyuaf.client.requests, ReadRequestTargetVector)
UAF_WRAP_CLASS("uaf/client/requests/translatebrowsepathstonodeidsrequesttarget.h", uafc , TranslateBrowsePathsToNodeIdsRequestTarget , COPY_YES, TOSTRING_YES, COMP_YES, pyuaf.client.requests, TranslateBrowsePathsToNodeIdsRequestTargetVector)
UAF_WRAP_CLASS("uaf/client/requests/writerequesttarget.h"                        , uafc , WriteRequestTarget                         , COPY_YES, TOSTRING_YES, COMP_YES, pyuaf.client.requests, WriteRequestTargetVector)
UAF_WRAP_CLASS("uaf/client/requests/historyreadrawmodifiedrequesttarget.h"       , uafc , HistoryReadRawModifiedRequestTarget        , COPY_YES, TOSTRING_YES, COMP_YES, pyuaf.client.requests, HistoryReadRawModifiedRequestTargetVector)
UAF_WRAP_CLASS("uaf/client/requests/basesessionrequest.h"                        , uafc , BaseSessionRequest                         , COPY_YES, TOSTRING_YES, COMP_NO,  pyuaf.client.requests, VECTOR_NO)
UAF_WRAP_CLASS("uaf/client/requests/basesubscriptionrequest.h"                   , uafc , BaseSubscriptionRequest                    , COPY_YES, TOSTRING_YES, COMP_NO,  pyuaf.client.requests, VECTOR_NO)


// define a macro to create synchronous session requests
%define CREATE_UAFC_SYNC_SESSIONREQUEST(SERVICE)
    %template(_##SERVICE##Request) uafc::BaseSessionRequest< uafc::BaseServiceConfig<uafc::SERVICE##Settings>, uafc::SERVICE##RequestTarget, false>;
    
    %pythoncode %{
    class SERVICE##Request(_##SERVICE##Request):
        def __init__(self, targets=0, serviceConfig=None, sessionConfig=None):
            if serviceConfig is None:
                serviceConfig = configs.SERVICE##Config()
            if sessionConfig is None:
                sessionConfig = configs.SessionConfig()
            _##SERVICE##Request.__init__(self, targets, serviceConfig, sessionConfig)
        def __repr__(self):
            return pyuaf.util.__get__repr__("pyuaf.client.requests." + #SERVICE + "Request", str(self))
    %}
        
        
%enddef


// define a macro to create asynchronous session requests
%define CREATE_UAFC_ASYNC_SESSIONREQUEST(SERVICE)
    %template(_Async##SERVICE##Request) uafc::BaseSessionRequest< uafc::BaseServiceConfig<uafc::SERVICE##Settings>, uafc::SERVICE##RequestTarget, true>;
    
    %pythoncode %{
    class Async##SERVICE##Request(_Async##SERVICE##Request):
        def __init__(self, targets=0, serviceConfig=None, sessionConfig=None):
            if serviceConfig is None:
                serviceConfig = configs.SERVICE##Config()
            if sessionConfig is None:
                sessionConfig = configs.SessionConfig()
            _Async##SERVICE##Request.__init__(self, targets, serviceConfig, sessionConfig)
        def __repr__(self):
            return pyuaf.util.__get__repr__("pyuaf.client.requests.Async" + #SERVICE + "Request", str(self))
    %}
    
%enddef


// create synchronous session requests
CREATE_UAFC_SYNC_SESSIONREQUEST(Read)
CREATE_UAFC_SYNC_SESSIONREQUEST(Write)
CREATE_UAFC_SYNC_SESSIONREQUEST(MethodCall)
CREATE_UAFC_SYNC_SESSIONREQUEST(TranslateBrowsePathsToNodeIds)
CREATE_UAFC_SYNC_SESSIONREQUEST(Browse)
CREATE_UAFC_SYNC_SESSIONREQUEST(BrowseNext)
CREATE_UAFC_SYNC_SESSIONREQUEST(HistoryReadRawModified)


// create asynchronous session requests
CREATE_UAFC_ASYNC_SESSIONREQUEST(Read)
CREATE_UAFC_ASYNC_SESSIONREQUEST(Write)
CREATE_UAFC_ASYNC_SESSIONREQUEST(MethodCall)


// define a macro to create synchronous subscription requests
%define CREATE_UAFC_SYNC_SUBSCRIPTIONREQUEST(SERVICE)
    %template(Base##SERVICE##Request) uafc::BaseSessionRequest< uafc::BaseServiceConfig<uafc::SERVICE##Settings>, uafc::SERVICE##RequestTarget, false>;
    %template(_##SERVICE##Request) uafc::BaseSubscriptionRequest< uafc::BaseServiceConfig<uafc::SERVICE##Settings>, uafc::SERVICE##RequestTarget, false>;

    %pythoncode %{
    class SERVICE##Request(_##SERVICE##Request):
        def __init__(self, targets=0, serviceConfig=None, sessionConfig=None, subscriptionConfig=None):
            if serviceConfig is None:
                serviceConfig = configs.SERVICE##Config()
            if sessionConfig is None:
                sessionConfig = configs.SessionConfig()
            if subscriptionConfig is None:
                subscriptionConfig = configs.SubscriptionConfig()
            _##SERVICE##Request.__init__(self, targets, serviceConfig, sessionConfig, subscriptionConfig)
        def __repr__(self):
            return pyuaf.util.__get__repr__("pyuaf.client.requests." + #SERVICE + "Request", str(self))
    %}
%enddef


// define a macro to create asynchronous subscription requests
%define CREATE_UAFC_ASYNC_SUBSCRIPTIONREQUEST(SERVICE)
    %template(BaseAsync##SERVICE##Request) uafc::BaseSessionRequest< uafc::BaseServiceConfig<uafc::SERVICE##Settings>, uafc::SERVICE##RequestTarget, true>;
    %template(_Async##SERVICE##Request) uafc::BaseSubscriptionRequest< uafc::BaseServiceConfig<uafc::SERVICE##Settings>, uafc::SERVICE##RequestTarget, true> ;

    %pythoncode %{
    class Async##SERVICE##Request(_Async##SERVICE##Request):
        def __init__(self, targets=0, serviceConfig=None, sessionConfig=None, subscriptionConfig=None):
            if serviceConfig is None:
                serviceConfig = configs.SERVICE##Config()
            if sessionConfig is None:
                sessionConfig = configs.SessionConfig()
            if subscriptionConfig is None:
                subscriptionConfig = configs.SubscriptionConfig()
            _Async##SERVICE##Request.__init__(self, targets, serviceConfig, sessionConfig, subscriptionConfig)
        def __repr__(self):
            return pyuaf.util.__get__repr__("pyuaf.client.requests.Async" + #SERVICE + "Request", str(self))
    %}
%enddef


// create synchronous subscription requests
CREATE_UAFC_SYNC_SUBSCRIPTIONREQUEST(CreateMonitoredData)
CREATE_UAFC_SYNC_SUBSCRIPTIONREQUEST(CreateMonitoredEvents)


// create asynchronous subscription requests
CREATE_UAFC_ASYNC_SUBSCRIPTIONREQUEST(CreateMonitoredData)
CREATE_UAFC_ASYNC_SUBSCRIPTIONREQUEST(CreateMonitoredEvents)


// include the requests header
%include "uaf/client/requests/requests.h"
