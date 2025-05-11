#include <iostream>
#include "auth.h"

using namespace std;

int main() {
    cout << "=== Welcome to the SP500 Trading Simulator ===\n";
    
    int choice;
    bool loggedIn = false;
    
    while (!loggedIn) {
        cout << "1. Sign In\n2. Sign Up\nChoose an option: ";
        cin >> choice;
        
        if (choice == 1)
            loggedIn = sign_in();
        else if (choice == 2)
            sign_up();
        else
            cout << "Invalid option.\n";
    }

    cout << "Trading bot online!\n";
    // Proceed to next features: load CSV, simulate investment, etc.

    return 0;
}
