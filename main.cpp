#include <iostream>
#include "auth.h"
#include <vector>
#include "sp500_data.h"
#include "portfolio.h"


using namespace std;

int main() {
    cout << "=== Welcome to the SP500 Trading Simulator ===\n";
    
    int choice;
    bool loggedIn = false;
    
    // while (!loggedIn) {
    //     cout << "1. Sign In\n2. Sign Up\nChoose an option: ";
    //     cin >> choice;
        
    //     if (choice == 1)
    //         loggedIn = sign_in();
    //     else if (choice == 2)
    //         sign_up();
    //     else
    //         cout << "Invalid option.\n";
    // }

    cout << "Trading bot online!\n";
    vector<SP500Entry> data = parse_csv("data/sp500.csv");
    for (const auto& entry : data ) {
        cout << "Date: " << entry.date << ", Close: " << entry.close << endl;
    }
    // Simulate Investment
    
    string buyDate;
    double amount;
    cout << "Enter investment date (YYYY-MM-DD): ";
    cin >> buyDate;
    cout << "Enter investment amount: ";
    cin >> amount;

    PortfolioEntry entry = invest_in_sp500(buyDate, amount, data);
    double valueNow = calculate_current_value(entry, data);

    cout << "You invested $" << amount << " on " << buyDate
         << ". It's now worth $" << valueNow << endl;

    return 0;

    return 0;
}
