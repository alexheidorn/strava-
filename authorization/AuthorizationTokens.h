//
// Created by alexh on 11/10/2024.
//

#ifndef AUTHORIZATIONTOKENS_H
#define AUTHORIZATIONTOKENS_H
#include <string>


class AuthorizationTokens {
    private:
        std::string clientID = "139095";
        std::string clientSecret = "f8faf24737d498daba841d1ed163f82c700dc84a";
        std::string authorizationCode = "7f312f64b54108f2fd2aec898bc275e2221c6a09";

        std::string access_token = "1693f696624a145e0657104cb332df3fe28b3675";

        std::string redirectURI = "http://localhost/exchange_token";
        std::string scope = "read";
        std::string responseType = "code";

    public:
        
        std::string refresh_token;
        std::string access_token_expires_at;
        std::string refresh_token_expires_at;

        std::string getClientID();
        std::string getClientSecret();
        std::string getAuthorizationCode();
        std::string getAccessToken();

        void setAuthorizationCode(std::string authorizationCode);
        
        void setAccessToken(std::string access_token);

};



#endif //AUTHORIZATIONTOKENS_H
