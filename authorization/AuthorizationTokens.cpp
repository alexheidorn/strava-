//
// Created by alexh on 11/10/2024.
//

#include "AuthorizationTokens.h"

std::string AuthorizationTokens::getClientID() {
    return clientID;
}

std::string AuthorizationTokens::getClientSecret() {
    return clientSecret;
}

std::string AuthorizationTokens::getAuthorizationCode() {
    return authorizationCode;
}

std::string AuthorizationTokens::getAccessToken() {
    return access_token;
}

void AuthorizationTokens::setAuthorizationCode(std::string authorizationCode) {
    this->authorizationCode = authorizationCode;
}

void AuthorizationTokens::setAccessToken(std::string access_token) {
    this->access_token = access_token;
}
