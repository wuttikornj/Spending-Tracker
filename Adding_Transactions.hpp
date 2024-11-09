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
    string category;        //Catagory
    string description;     //Description

    //Expense(string d, double a, string c, string desc)
    //    : date(d), amount(a), category(c), description(desc) {}
};

class MoneyTracker : public Expense{
private:
   //vector<Expense> expenses;

public:
    //void addAmount(double amount);
    void addingTransaction();
    string getToday();
//    void viewExpenses() {
//        for (const auto &expense : expenses) {
//            cout << "Date: " << expense.date << ", Amount: " << expense.amount
//                 << ", Category: " << expense.category << ", Description: " << expense.description << endl;
//        }
//    }

};

#endif /* Adding_Transactions_hpp */
