//
// Created by saga on 11/8/2024.
//

#include "CurlRequests.h"

#include <iostream>


void CurlRequests::requestAccessToken(const std::string access_token) {
}

void CurlRequests::setHeaders() {
    curlHeaders = curl_slist_append(curlHeaders, ("Authorization: Bearer " + access_token).c_str());
    curl_easy_setopt(curlHandle, CURLOPT_HTTPHEADER, curlHeaders);
}

void CurlRequests::makeRequest() {
    // Set the URL for the Strava API endpoint to retrieve the logged-in athlete's details
    curl_easy_setopt(curlHandle, CURLOPT_URL, stravaAthlete);

    // Set up the callback function to capture the response
    curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &readBuffer);

    // Perform the request
    curlResult = curl_easy_perform(curlHandle);

    // Check for errors
    if(curlResult != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(curlResult) << std::endl;
    } else {
        std::cout << "Logged-in Athlete Information:\n" << readBuffer << std::endl;
    }
}
