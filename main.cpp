//
// Created by saga on 11/8/2024.
//


#include <iostream>

#include "CurlRequests.h"

int main() {
    const std::string accessToken = "1e3e5c584a81bcc743b5254d5114baeda0b47aee";
    CurlRequests curlRequests;
    curlRequests.setAccessToken(accessToken);

    CURLcode curlResult = curlRequests.makeRequest(curlRequests.stravaAthlete.c_str());

    // Check for errors
    if(curlResult != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(curlResult) << std::endl;
    } else {
        std::cout << "Logged-in Athlete Information:\n" << curlRequests.getReadBuffer() << std::endl;
    }

    curlRequests.makeRequest(curlRequests.stravaActivity.c_str());
}
