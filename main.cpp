//
// Created by saga on 11/8/2024.
//


#include <iostream>

#include "CurlRequests.h"

int main() {
    const std::string accessToken = "1e3e5c584a81bcc743b5254d5114baeda0b47aee";
    CurlRequests curlRequests;
    curlRequests.setAccessToken(accessToken);

    curlRequests.makeRequest(curlRequests.stravaAthlete.c_str());

    curlRequests.makeRequest(curlRequests.stravaActivity.c_str());
}
