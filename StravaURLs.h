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
        std::string stravaActivity = "https://www.strava.com/api/v3/athlete/activity";
        // std::string stravaToken = "https://www.strava.com/oauth/token";
        // std::string stravaRefreshToken = "https://www.strava.com/oauth/token";
        std::string stravaOAuth = "http://www.strava.com/oauth/authorize?client_id=" + tokens.getClientID() +"&response_type=code&redirect_uri=http://localhost/exchange_token&approval_prompt=force&scope=read";
};



#endif //STRAVAURLS_H
