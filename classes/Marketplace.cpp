#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "../headers/User.h"
#include "../headers/Marketplace.h"

using namespace std;


Marketplace::Marketplace(): isLogged(false), loggedLogin(""), loggedPassword(""), foundUser("","") {}

void Marketplace::registerUser(){

    string writtenLogin;
    string writtenPassword;
    cout << "For registering, write down your login \n";

    bool validLogin = false;

    while(!validLogin){
        cin >> writtenLogin;
        validLogin = !verifyIfLoginExists(writtenLogin);
        

        if(!validLogin){
            cout << "This login already exists \n";
            cout << "Write another login \n";
        }
    }

    cout << "Now, write down you password \n";

    bool validPassword = false;
    while(!validPassword){
        cin >> writtenPassword;
        

        validPassword = verifyIfPasswordIsValid(writtenPassword);
        if(validPassword){
            cout << "Your password needs to have at least 4 digits and less than 12 digits";
        }
    }

    cout << "You are now registered \n"; 
    users.push_back(User(writtenLogin, writtenPassword));

    loggedLogin = writtenLogin;
    loggedPassword = loggedPassword;
}

void Marketplace::loginUser(){
    bool logging = true;

    while(logging){
        string writtenLogin;
        string writtenPassword;
        
        cout << "Write down your login \n";
        cin >> writtenLogin;

        clearScreen();
        if(verifyIfPasswordIsValid(writtenPassword)){
            do{
            cout << "Now write down your password \n";
            cin >> writtenPassword;

            logging = !verifyIfPasswordIsCorrect(writtenPassword);
            } while (logging);
        }
    }
}

bool Marketplace::verifyIfLoginExists(string login){

    for(User& u : users){
        if(u.getLogin() == login)
        foundUser = u;
        return true;
    }

    return false;
}

bool Marketplace::verifyIfPasswordIsValid(string password){
    
    if(password.length() < 4 || password.length() > 12){
        return true;
    }

    return false;
}

bool Marketplace::verifyIfPasswordIsCorrect(string password){
    
    if(foundUser.getPassword() == password){
        return true;
    }

    return false;
}

void Marketplace::clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

