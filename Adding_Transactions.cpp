//
//  Adding_Transactions.cpp
//  Tracker
//
//  Created by Wuttikorn Jiraroongrojana on 11/8/24.
//

#include "Adding_Transactions.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <regex>
#include <string>
using namespace std;

void MoneyTracker::addingTransaction(){ // recieved from the check
    char choice;
    regex datePattern(R"(^\d{1,2}/\d{1,2}/\d{4}$)");

    do{                                                     // check if amount is valid NEED FIXING
        cout << endl << "Adding Transaction" <<endl;
        cout << "Amount: ";
        cin >> amount;
        
        do {                                                // check if the date is valid
            cout << "Date [type DD/MM/YYYY or 'Today']: ";
            cin >> date; // Read user input

            // Check if the input matches "Today" or the date pattern
            if (date == "Today" || regex_match(date, datePattern)) {
                cout << "Valid input received: " << date << endl;
            } else {
                cout << "Invalid input. Please enter in DD/MM format or 'Today'." << endl;
            }
        } while (true); // Repeat until valid input is given

        cout << "Description: ";
        cin >> description;

        // cout << "Category: ";            Create later
        // cin >> category;

        cout << endl;
        cout << "Loading";
        for (int i = 0; i < 4; ++i) {
            cout << ".";                // Print a dot
            cout.flush();               // Flush the output buffer to display the dot immediately
            this_thread::sleep_for(chrono::milliseconds(500));  // Pause for the delay
        }
        cout << "\rTransaction added successfully!";
        cout.flush();
        cout << endl; // why not working??
        cout << endl;
        cout << "Do you want to add another transaction? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

// void MoneyTracker::addAmount(double amount){
    
// }

