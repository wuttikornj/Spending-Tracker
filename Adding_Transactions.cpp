//
//  Adding_Transactions.cpp
//  Tracker
//
//  Created by Wuttikorn Jiraroongrojana on 11/8/24.
//

#include "Adding_Transactions.hpp"
#include "menu.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <regex>
#include <string>
using namespace std;

void MoneyTracker::addingTransaction(){ 
    char choice;
    regex datePattern("^\\d{1,2}/\\d{1,2}/\\d{4}$");
    string today = getToday();
    int transactionID =1;
    do{ 
        cout << endl << "Adding Transaction" <<endl;
        cout << "Amount: £";
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

        cout << "Category: " << endl;
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
        string DisplayCat;
        switch (category) {
            case 1:
                DisplayCat = " 🍛 1. Food";
                break;
            case 2:
                DisplayCat = " 👔 2. Clothing";
                break;
            case 3:
                DisplayCat = " 🚈 3. Transportation";
                break;
            case 4:
                DisplayCat = " 🛒 4. Shopping";
                break;
            case 5:
                DisplayCat = " 🎥 5. Entertainment";
                break;
            case 6:
                DisplayCat = " 🤔 6. Other";
                break;
        }


        cout << endl;
        cout << "********************************************************************************";
        cout << endl;
        cout << "Confirm transaction details:" << endl;
        cout << "Date:          " << date << endl;
        cout << "Amount:        £" << amount << endl;
        cout << "Description:   " << description << endl;
        cout << "Category:     " << DisplayCat << endl;  //Change so that it can display a string
        cout << "Is this correct? (y/n): ";
        cin >> choice;
        cout << endl;
        if (choice == 'y' || choice == 'Y') {
            // fucntion to Add Transaction to CSV File"
            // Check for last Transaction ID 
            ifstream file("transactions.csv");
                if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    stringstream ss(line);
                    string idStr;
                    getline(ss, idStr, ','); // Read the ID from the line
                    transactionID = stoi(idStr) + 1; // Increment the ID
                }
                file.close();
            }
            //Adding Transaction
            ofstream outfile("transactions.csv", ios::app);
            if (outfile.is_open()) {
                outfile << transactionID << "," << amount << "," << date << "," << DisplayCat << "," << description << "\n";
                outfile.close();
                //cout << "Transaction added and saved to CSV file successfully!" << endl;
                cout << endl;
                cout << "Adding Transaction";
                for (int i = 0; i < 4; ++i) {
                    cout << ".";                
                    cout.flush();               
                    this_thread::sleep_for(chrono::milliseconds(500));  
                }
                cout << "\rTransaction added successfully! ✅";
                cout.flush();
                cout << endl; 
                cout << endl;
            } else {
                cerr << "Error: Unable to open the file for writing." << endl;
            }
        } else {
            cout << "Transaction not added." << endl;
        }
        cout << "********************************************************************************" << endl;
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

void MoneyTracker::viewTransactions() {
    std::ifstream file("transactions.csv");
    if (file.is_open()) {
        string line;
        cout << endl;
        cout << "Transactions:\n";
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open the file for reading." << std::endl;
    }
}
void MoneyTracker:: deleteTransaction(const int& transactionId) {
    vector<string> transactions;
    string line;
    int currentID =1;
    // Read CSV file
    ifstream inputFile("transactions.csv");
    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(inputFile, line)) {
        if (currentID != transactionId) {
            transactions.push_back(line);
        }
        currentID++;
    }
    inputFile.close();

    // Identify and remove the transaction
    ofstream outputFile("transactions.csv", ios::trunc); // write mode to overwrite
    if (!outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    for (const auto& transaction : transactions) {
        // Assuming the transaction ID is the first element in the CSV row
        outputFile << transaction << "\n";
        // if (transaction.substr(0, transaction.find(',')) != transactionId) {
        //     outputFile << transaction << endl; // Write back the transaction if not deleted
        // }
    }

    outputFile.close();
    cout << "Transaction deleted successfully." << endl;
    cout << endl;
    cout << endl;
}