//
// Created by alexh on 11/8/2024.
//

#include "CurlRequests.h"



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
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    // Perform the request
    res = curl_easy_perform(curl);

    // Check for errors
    if(res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    } else {
        std::cout << "Logged-in Athlete Information:\n" << readBuffer << std::endl;
    }
}
