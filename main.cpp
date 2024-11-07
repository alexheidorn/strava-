//
// Created by saga on 11/7/2024.
//

#include <iostream>
#include <curl/curl.h>
#include <string>

// Callback function to handle the API response
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    // Replace this with your Strava API access token
    std::string access_token = "YOUR_ACCESS_TOKEN";
    std::string readBuffer;

    // Initialize CURL
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        // Set the URL for the Strava API endpoint to retrieve the logged-in athlete's details
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.strava.com/api/v3/athlete");

        // Set the Authorization header with the access token
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + access_token).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Set up the callback function to capture the response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Logged-in Athlete Information:\n" << readBuffer << std::endl;
        }

        // Cleanup
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    return 0;
}
