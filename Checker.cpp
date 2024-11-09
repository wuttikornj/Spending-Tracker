//
//  Checker.cpp
//  Tracker
//
//  Created by Wuttikorn Jiraroongrojana on 11/8/24.
//

#include "Checker.hpp"
#include "Adding_Transactions.hpp"
#include <iostream>
using namespace std;

//checking the number from the menu and sending it to what ever they are assign to
// Adding transaction
// Viewing Transaction
// Deleteing Transaction
// Exit

void Checker::checking(int Num_Menu){
    if (Num_Menu == 1){  // Adding transaction
        MoneyTracker Tracker;
        Tracker.addingTransaction();
    }
    else if (Num_Menu == 2){ // Viewing Transaction
        cout<<"Havin't made other functions yet, Slow down" << endl;
        exit(0);
    }
    else if (Num_Menu == 3){ // Deleteing Transaction
        cout<<"Havin't made other functions yet, Slow down" << endl;
        exit(0);
    }
    else if (Num_Menu == 4){ // Exit
        cout << endl;
        cout<<"Thanks for useing the Money Tracker" << endl;
        exit(0);
    }
}
