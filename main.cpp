#include <iostream>
#include "auth.h"
#include <vector>
#include "sp500_data.h"
#include "portfolio.h"
#include "data_cleaner.h"


using namespace std;

int main() {
    cout << "=== Welcome to the SP500 Trading Simulator ===\n";
    
    int choice;
    bool loggedIn = false;
    

    cout << "Trading bot online!\n";
    vector<SP500Entry> data = parse_csv("data/sp500_cleaned.csv");

    
    // Simulate Investment
    string buyDate;
    double amount;
    cout << "Enter investment date (MM/DD/YYYY): ";
    cin >> buyDate;
    cout << "Enter investment amount: ";
    cin >> amount;

    PortfolioEntry entry = invest_in_sp500(buyDate, amount, data);
    double valueNow = calculate_current_value(entry, data);

    cout << "You invested $" << amount << " on " << buyDate
         << ". It's now worth $" << valueNow << endl;

    return 0;

}
