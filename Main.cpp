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
            cout << "1 - REGISTER | 2- LOGIN \n" << "3 - BUY | 4 - SELL \n" << "5 - LOGOUT | 6 - EXIT \n" << "7 - dEbUg \n";
            cin >> option;
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (option)
            {
            case 1:
                if(market.isLogged){
                    cout << "You are already logged in!";
                }
                else{
                    market.registerUser();
                }
                break;

            case 2:
                if(market.isLogged){
                    cout << "You are already logged in!";
                }
                else{
                    market.loginUser();
                }
                break;

            case 6:
                cout << "Quiting...";
                exit(0);
                break;
            default:
                break;
            }

        }

        return 0;
    }