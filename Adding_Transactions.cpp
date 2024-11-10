//
//  Adding_Transactions.cpp
//  Tracker
//
//  Created by Wuttikorn Jiraroongrojana on 11/8/24.
//

#include "Adding_Transactions.hpp"
#include "menu.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <regex>
#include <string>
using namespace std;

void MoneyTracker::addingTransaction(){ 
    char choice;
    regex datePattern("^\\d{1,2}/\\d{1,2}/\\d{4}$");
    string today = getToday();

    do{ 
        cout << endl << "Adding Transaction" <<endl;
        cout << "Amount: ";
        cin >> amount;
        
        do { 
            cout << "Date [type DD/MM/YYYY or 'Today']: ";
            cin >> date; 

            if (date == "Today") {
                date = today;
                cout << "Valid input received: " << date << endl;
                break;
            } else if (regex_match(date, datePattern)) {
                cout << "Valid input received: " << date << endl;
                break;
            } else {
                cout << "Invalid input. Please enter in DD/MM/YYYY format or 'Today'." << endl;
            }
        } while (true); 

        cout << "Description: ";
        cin.ignore(); // ignore newline character left in input buffer
        getline(cin, description);

        cout << "Category: ";
        cout << " 🍛 1. Food" << endl;
        cout << " 👔 2. Clothing" << endl;
        cout << " 🚈 3. Transportation" << endl;
        cout << " 🛒 4. Shopping" << endl;
        cout << " 🎥 5. Entertainment" << endl;
        cout << " 🤔 6. Other" << endl;
        cout << "Enter your choice [1-6] : ";
        cin >> category;
        if (category < 1 || category > 6) {
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl
            << "Press any key to continue...";
            cin.get();
            continue;
        }

        


        cout << endl;
        cout << "Confirm transaction details:" << endl;
        cout << "Date: " << date << endl;
        cout << "Amount: " << amount << endl;
        cout << "Description: " << description << endl;
        cout << "Category: " << category << endl;  //Change so that it can display a string
        cout << "Is this correct? (y/n): ";
        cin >> choice;
        cout << endl;
        if (choice == 'y') {
            cout << "Confirmed and continueing." << endl;
        } else {
            cout << "Transaction not added." << endl;
            }
        cout << endl;
        //"Adding Transaction to Database"


        for (int i = 0; i < 4; ++i) {
            cout << ".";                
            cout.flush();               
            this_thread::sleep_for(chrono::milliseconds(500));  
        }
        cout << "\rTransaction added successfully!";
        cout.flush();
        cout << endl; 
        cout << endl;
        cout << "Do you want to add another transaction? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            MainMenu Display;
            Display.menu();
        }
    } while (choice == 'y' || choice == 'Y');
}

string MoneyTracker::getToday() {
    time_t t = time(0);
    tm* now = localtime(&t);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", now);
    return string(buffer);
}

/*
saving_expense_to_file
*/