//
// Created by saga on 11/8/2024.
//

#ifndef CURLREQUESTS_H
#define CURLREQUESTS_H

#include <stdexcept>
#include <curl/curl.h>
#include <string>

// Callback function to handle the API response
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

class CurlRequests {
private:
    // Replace this with your Strava API access token
    std::string access_token;
    std::string readBuffer;
    CURL* curlHandle;
    CURLcode curlResult;

    struct curl_slist* curlHeaders = nullptr;


public:
    CurlRequests() {
        curlHandle = curl_easy_init();
        if (!curlHandle) {
            throw std::runtime_error("curl_easy_init() failed");
        }
    }
    ~CurlRequests() {
        curl_easy_cleanup(curlHandle);
        curl_slist_free_all(curlHeaders);
    }
    // strava URL requests
    std::string stravaAthlete = "https://www.strava.com/api/v3/athlete";
    std::string stravaActivity = "https://www.strava.com/api/v3/athlete/activity";

    void setAccessToken(const std::string& token);
    std::string requestAuthorizationToken(const std::string& access_token);
    void setHeaders();
    void makeRequest(const char* stravaURL);
    std::string getReadBuffer();

};



#endif //CURLREQUESTS_H
