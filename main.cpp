//
//  main.cpp
//  Tracker
//
//  Created by Wuttikorn Jiraroongrojana on 11/8/24.
//

#include <iostream>
//#include "Checker.hpp"
#include "Checker.cpp"              //Manual Compile?!!!!
#include "Adding_Transactions.cpp"

using namespace std;


int options = 0;

void menu(){
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
}

int main() {
    cout << endl;
    cout << "Welcome to Money Tracker" << endl;
    cout << endl;
    menu();
    Checker checker1;
    checker1.checking(options);
    

    return 0;
}
