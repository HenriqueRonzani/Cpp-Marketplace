
#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "User.h"


class Marketplace{

private:

public:

    std::vector<User> users;

    bool isLogged;
    std::string loggedLogin;
    std::string loggedPassword;
    User foundUser;

    Marketplace();

    void registerUser();

    void loginUser();

    void logoutUser();

    bool verifyIfLoginExists(std::string login);

    bool verifyIfPasswordIsValid(std::string password);

    bool verifyIfPasswordIsCorrect(std::string password);

    void clearScreen();
};

#endif