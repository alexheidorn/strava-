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

    // tokens.setAccessToken("1693f696624a145e0657104cb332df3fe28b3675");

    curlRequests.makeRequest(stravaURLs.stravaAthlete.c_str());

    curlRequests.makeRequest(stravaURLs.stravaActivity.c_str());
}
