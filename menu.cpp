#include "menu.hpp"
#include "Adding_Transactions.hpp"
//#include "Adding_Transactions.cpp"
#include <iostream>
using namespace std;
int options = 0;

void MainMenu::menu(){
    cout << "Please choose a number to procede" << endl;
    cout << "1. Add Transactions" << endl;
    cout << "2. View Past Transactions" << endl;
    cout << "3. Delete Transactionss" << endl;
    cout << "4. Exit" << endl;
    cout << "Please select a [ 1-4 ]: ";
    cin >> options;
    while (options < 1 || options > 4){
        cout << "You entered a number greater than 4, try again" << endl;
        cin >> options;
    }
    MainMenu checker1;
    checker1.checking(options);
}

void MainMenu::checking(int Num_Menu){
    switch (Num_Menu) {
        case 1: {
            MoneyTracker Tracker;
            Tracker.addingTransaction();
            break;
        }
        case 2:
            cout << "Functionality not implemented yet." << endl;
            break;
        case 3:
            cout << "Functionality not implemented yet." << endl;
            break;
        case 4:
            cout << endl;
            cout << "Thanks for using the Money Tracker" << endl;
            exit(0);
        default:
            cout << "Invalid menu option." << endl;
            break;
    }
}