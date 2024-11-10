//
// Created by saga on 11/8/2024.
//


#include <iostream>

#include "CurlRequests.h"
#include "StravaURLs.h"

int main() {
    AuthorizationTokens tokens;
    StravaURLs stravaURLs;
    CurlRequests curlRequests;
    curlRequests.setAccessToken(tokens.access_token);

    curlRequests.makeRequest(stravaURLs.stravaAthlete.c_str());

    curlRequests.makeRequest(stravaURLs.stravaActivity.c_str());
}
