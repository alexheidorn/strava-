//
// Created by saga on 11/8/2024.
//

#ifndef CURLREQUESTS_H
#define CURLREQUESTS_H

#include <curl/curl.h>
#include <string>


class CurlRequests {
private:
    // Replace this with your Strava API access token
    std::string access_token = "93fa4b6c3a39d4ee147dc7ca952fd51412162394";
    std::string readBuffer;
    CURL* curlHandle = curl_easy_init();
    CURLcode curlResult;

    struct curl_slist* curlHeaders = NULL;


    // strava URL requests
    std::string stravaGetAthlete = "https://www.strava.com/api/v3/athlete";


public:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
    void requestAccessToken(std::string access_token);
    void setHeaders(curl_slist* headers);
    void getAthlete(std::string access_token, );

};



#endif //CURLREQUESTS_H
