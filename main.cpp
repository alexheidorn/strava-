//
// Created by saga on 11/8/2024.
//


#include <iostream>

#include "CurlRequests.h"

int main() {
    CURLcode curlResult;
    CurlRequests curlRequests;
    curlResult = curlRequests.makeRequest(curlRequests.stravaAthlete.c_str());
    curlRequests.makeRequest(curlRequests.stravaActivity.c_str());

    // Check for errors
    if(curlResult != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(curlResult) << std::endl;
    } else {
        std::cout << "Logged-in Athlete Information:\n" << readBuffer << std::endl;
    }
}
