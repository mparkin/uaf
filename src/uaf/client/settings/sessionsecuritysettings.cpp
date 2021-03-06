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

#include "uaf/client/settings/sessionsecuritysettings.h"

namespace uafc
{
    using namespace uaf;
    using namespace uafc;
    using std::string;
    using std::stringstream;
    using std::vector;
    using std::size_t;


    // Constructor
    // =============================================================================================
    SessionSecuritySettings::SessionSecuritySettings()
    : securityPolicy(securitypolicies::UA_None),
      messageSecurityMode(messagesecuritymodes::Mode_None),
      userTokenType(usertokentypes::Anonymous)
    {}


    // Get a string representation
    // =============================================================================================
    string SessionSecuritySettings::toString(const string& indent, size_t colon) const
    {
        stringstream ss;

        ss << indent << " - securityPolicy";
        ss << fillToPos(ss, colon);
        ss << ": " << securityPolicy << "\n";

        ss << indent << " - messageSecurityMode";
        ss << fillToPos(ss, colon);
        ss << ": " << messageSecurityMode << " (" << messagesecuritymodes::toString(messageSecurityMode) << ")\n";

        ss << indent << " - userTokenType";
        ss << fillToPos(ss, colon);
        ss << ": " << userTokenType << " (" << usertokentypes::toString(userTokenType) << ")\n";

        ss << indent << " - userName";
        ss << fillToPos(ss, colon);
        ss << ": " << userName << "\n";

        ss << indent << " - userPassword";
        ss << fillToPos(ss, colon);
        ss << ": " << userPassword << "\n";

        ss << indent << " - userCertificateFileName";
        ss << fillToPos(ss, colon);
        ss << ": " << userCertificateFileName << "\n";

        ss << indent << " - userPrivateKeyFileName";
        ss << fillToPos(ss, colon);
        ss << ": " << userPrivateKeyFileName;

        return ss.str();
    }

    // Match a SessionSecuritySettings with an EndpointDescription.
    // =============================================================================================
    Status match(
            const SessionSecuritySettings&    settings,
            const EndpointDescription&        endpoint)
    {
        vector<UserTokenPolicy> tokens = endpoint.userIdentityTokens;

        for (vector<UserTokenPolicy>::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
        {
            if (   settings.userTokenType       == it->tokenType
                && settings.messageSecurityMode == endpoint.securityMode
                && settings.securityPolicy      == endpoint.securityPolicyUri)
            {
                return Status(statuscodes::Good);
            }
        }

        return Status(statuscodes::SecurityError, "Bad match");
    }


    // Match multiple SessionSecuritySettings with multiple EndpointDescription.
    // =============================================================================================
    uaf::Status match(
            const vector<SessionSecuritySettings>&  settings,
            const vector<EndpointDescription>&      endpoints,
            SessionSecuritySettings&                suitableSettings,
            EndpointDescription&                    suitableEndpoint)
    {
        uaf::Status ret;

        vector<SessionSecuritySettings>::const_iterator settingsIter;
        vector<EndpointDescription>::const_iterator     endpointsIter;

        for (settingsIter = settings.begin(); settingsIter != settings.end(); ++settingsIter)
        {
            for (endpointsIter = endpoints.begin(); endpointsIter != endpoints.end(); ++endpointsIter)
            {
                if (match(*settingsIter, *endpointsIter).isGood())
                {
                    suitableSettings = *settingsIter;
                    suitableEndpoint = *endpointsIter;

                    return Status(statuscodes::Good);
                }
            }
        }

        return Status(statuscodes::SecurityError,
                      "No given session security settings matched an endpoint");
    }

}
