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

    clearScreen();
    cout << "For registering, write down your login \n";

    bool validLogin = false;

    while(!validLogin){
        cin >> writtenLogin;
        validLogin = !verifyIfLoginExists(writtenLogin);
        

        if(!validLogin){
            clearScreen();
            cout << "This login already exists \n";
            cout << "Write another login \n";
        }
    }

    clearScreen();
    cout << "Now, write down you password \n";

    bool validPassword = false;
    while(!validPassword){
        cin >> writtenPassword;

        validPassword = verifyIfPasswordIsValid(writtenPassword);
        if(!validPassword){
            clearScreen();
            cout << "Your password needs to have at least 4 digits and less than 12 digits \n";
            cout << "Write it again \n";
        }
    }

    clearScreen();
    cout << "You are now registered \n"; 
    users.push_back(User(writtenLogin, writtenPassword));

    loggedLogin = writtenLogin;
    loggedPassword = loggedPassword;
    system("pause");
}

void Marketplace::loginUser(){

    bool logging = true;

    while(logging){
        string writtenLogin;
        string writtenPassword;
        
        clearScreen();
        cout << "Write down your login \n";
        cin >> writtenLogin;

        if(verifyIfLoginExists(writtenLogin)){
            do{
            clearScreen();
            cout << "Now write down your password \n";
            cin >> writtenPassword;

            logging = !verifyIfPasswordIsCorrect(writtenPassword);

            } while (logging);
        }
        else{
            clearScreen();
            cout << "This login does not exist!";
            system("pause");
        }
    }

    loggedLogin = foundUser.getLogin();
    loggedPassword = foundUser.getPassword();
    isLogged = true;

    clearScreen();
    cout << "You are now logged in \n";
    system("pause");
}

void Marketplace::logoutUser(){
    isLogged = false;
    loggedLogin = "";
    loggedPassword = "";
    cout << "You have logged in";
    system("pause");
}

bool Marketplace::verifyIfLoginExists(string login){

    for(User& u : users){
        if(u.getLogin() == login){
            foundUser = u;
            return true;
        }
    }

    foundUser = User("","");
    return false;
}

bool Marketplace::verifyIfPasswordIsValid(string password){
    
    if(password.length() < 4 || password.length() > 12){
        return false;
    }

    return true;
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