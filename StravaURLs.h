//
// Created by alexh on 11/10/2024.
//

#ifndef STRAVAURLS_H
#define STRAVAURLS_H
#include <string>
#include "authorization/AuthorizationTokens.h"


class StravaURLs {
    private:
        AuthorizationTokens tokens;
    public:
        // strava URL requests
        std::string stravaAthlete = "https://www.strava.com/api/v3/athlete";
        std::string stravaActivity = "https://www.strava.com/api/v3/athlete/activities";
        // std::string stravaToken = "https://www.strava.com/oauth/token";
        // std::string stravaRefreshToken = "https://www.strava.com/oauth/token";
        std::string stravaOAuthPage = "http://www.strava.com/oauth/authorize"
        std::string get_fields = "client_id=" + tokens.getClientID() +"&response_type=code&redirect_uri=http://localhost/exchange_token&approval_prompt=force&scope=read_all,activity:read_all";
        
        std::string stravaExchangeToken = "https://www.strava.com/oauth/token";
        std::string exchange_post_fields = "client_id=" + std::string(client_id) +
                                  "&client_secret=" + std::string(client_secret) +
                                  "&code=" + std::string(code) +
                                  "&grant_type=authorization_code";
};



#endif //STRAVAURLS_H
