#include <iostream>
#include "auth.h"
#include <vector>
#include "sp500_data.h"
#include "portfolio.h"
#include "data_cleaner.h"


using namespace std;

int main() {
    clean_sp500_csv("data/historicaldata.csv", "data/sp500_cleaned.csv");
    return 0;
    // cout << "=== Welcome to the SP500 Trading Simulator ===\n";

    // std::cout << "Fetching SP500 (SPY) data..." << std::endl;

    // system("mkdir -p data && curl -o data/sp500.csv \"https://query1.finance.yahoo.com/v7/finance/download/SPY?period1=1673040000&period2=1704576000&interval=1d&events=history\"");

    
    // int choice;
    // bool loggedIn = false;
    
    // // while (!loggedIn) {
    // //     cout << "1. Sign In\n2. Sign Up\nChoose an option: ";
    // //     cin >> choice;
        
    // //     if (choice == 1)
    // //         loggedIn = sign_in();
    // //     else if (choice == 2)
    // //         sign_up();
    // //     else
    // //         cout << "Invalid option.\n";
    // // }

    // cout << "Trading bot online!\n";
    // vector<SP500Entry> data = parse_csv("data/sp500.csv");
    // for (const auto& entry : data ) {
    //     cout << "Date: " << entry.date << ", Close: " << entry.close << endl;
    // }
    // // Simulate Investment

    // string buyDate;
    // double amount;
    // cout << "Enter investment date (YYYY-MM-DD): ";
    // cin >> buyDate;
    // cout << "Enter investment amount: ";
    // cin >> amount;

    // PortfolioEntry entry = invest_in_sp500(buyDate, amount, data);
    // double valueNow = calculate_current_value(entry, data);

    // cout << "You invested $" << amount << " on " << buyDate
    //      << ". It's now worth $" << valueNow << endl;

    // return 0;

}
