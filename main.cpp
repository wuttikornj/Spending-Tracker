//
//  main.cpp
//  Tracker
//
//  Created by Wuttikorn Jiraroongrojana on 11/8/24.
//

#include <iostream>
#include "menu.hpp"
#include "menu.cpp"
#include "Adding_Transactions.cpp"

using namespace std;

int main() {
    cout << endl;
    cout << "Welcome to Money Tracker" << endl;
    cout << endl;
    do{
        MainMenu Display;
        Display.menu();
    } while (options != 4);

    return 0;
}
