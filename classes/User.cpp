#include <string>
#include "../headers/User.h"

using namespace std;

User::User(string userLogin, string userPassword) {
    login = userLogin;
    password = userPassword;
}

void User::setLogin(string newLogin){
    this->login = newLogin;
}

string User::getLogin(){
    return this->login;
}

void User::setPassword(string newPassword){
    this->password = newPassword;
}

string User::getPassword(){
    return this->password;
}
