#ifndef USER_H
#define USER_H

#include <string>

class User
{
private:
    std::string login;
    std::string password;

public:
    User(std::string userLogin, std::string userPassword);

    void setLogin(std::string newLogin);
    std::string getLogin();

    void setPassword(std::string newPassword);
    std::string getPassword();
};

#endif