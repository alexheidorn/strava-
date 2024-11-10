//
// Created by alexh on 11/10/2024.
//

#ifndef AUTHORIZATIONTOKENS_H
#define AUTHORIZATIONTOKENS_H
#include <string>


class AuthorizationTokens {
    private:
        static int clientID = 139095;
        std::string clientSecret;

    public:
        std::string access_token;
        std::string refresh_token;
        std::string access_token_expires_at;
        std::string refresh_token_expires_at;

        static int getClientID();
        static std::string getClientSecret();
};



#endif //AUTHORIZATIONTOKENS_H
