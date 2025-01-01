//
// Created by saga on 11/8/2024.
//

#ifndef CURLREQUESTS_H
#define CURLREQUESTS_H

#include <stdexcept>
#include <curl/curl.h>
#include <string>

#include "AuthorizationTokens.h"

// Callback function to handle the API response
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

class CurlRequests {
private:
    AuthorizationTokens tokens;
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

    // request access-> full authorization workflow
    std::string requestAccess();

    // get authorization code
    std::string retrieveAuthorizationCode(const std::string& redirectURI);

    // exchange authorization code for access token & refresh token
    std::string exchangeToken(const std::string& authorizationCode);

    // refresh access token
    std::string refreshAccessToken(const std::string& refresh_token);

    void setAuthorizationHeader();
    void makeRequest(const char* stravaURL);
    bool checkForError();
    std::string getReadBuffer();

};



#endif //CURLREQUESTS_H
