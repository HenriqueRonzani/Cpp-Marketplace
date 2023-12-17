#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>

#include "headers/User.h"
#include "headers/Marketplace.h"

using namespace std;

int main(int argc, char const *argv[])
    {
        bool loop = true;
        Marketplace market;
        int option;
        
        while (loop){
            market.clearScreen();

            cout << "Wellcome to the marketplace \n";
            cout << "What are you gonna do? \n";
            cout << "1 - REGISTER | 2- LOGIN \n" << "3 - BUY | 4 - SELL \n" << "5 - LOGOUT | 6 - EXIT \n";
            cin >> option;
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (option)
            {
            case 1:
                if(market.isLogged){
                    cout << "You are already logged in! \n";
                    system("pause");
                }
                else{
                    market.registerUser();
                }
                break;

            case 2:
                if(market.isLogged){
                    cout << "You are already logged in! \n";
                    system("pause");
                }
                else{
                    market.loginUser();
                }
                break;
                
            case 5:
                if(!market.isLogged){
                    cout << "You are not logged in! \n";
                    system("pause");
                }
                else{
                    market.isLogged = false;
                    market.loggedLogin = "";
                    market.loggedPassword = "";
                    cout << "You have logged you";
                    system("pause");
                }
                break;

            case 6:
                cout << "Quiting...";
                exit(0);
                break;

            case 7:
                //Debugging purposes
                for(User& u : market.users){
                    cout << u.getLogin() << " and " << u.getPassword() << "\n";
                }
                cout << "isLogged = " << market.isLogged << "\n";
                system("pause");
                break;

            default:
                cout << "Choose a valid option! \n";
                system("pause");
                break;
            }

        }

        return 0;
    }