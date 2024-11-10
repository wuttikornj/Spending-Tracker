//
//  Adding_Transactions.hpp
//  Tracker
//
//  Created by Wuttikorn Jiraroongrojana on 11/8/24.
//

#ifndef Adding_Transactions_hpp
#define Adding_Transactions_hpp

#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

class Expense{
public:
    string date;            //date
    double amount;          //cost
    int category;        //Catagory
    string description;     //Description
};

class MoneyTracker : public Expense{
public:
    void addingTransaction();
    string getToday();
    void viewTransactions();
    void deleteTransaction(const int& transactionId);
};

#endif /* Adding_Transactions_hpp */
