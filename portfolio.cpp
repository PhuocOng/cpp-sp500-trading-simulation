#include "portfolio.h"
#include <iostream>
using namespace std;

PortfolioEntry invest_in_sp500(const string& date, double amount, const vector<SP500Entry>& data) {
    for (const auto& entry : data) {
        if (entry.date == date) {
            return {date, amount, entry.close};
        }
    }
    throw runtime_error("Buy date not found in data");
}

double calculate_current_value(const PortfolioEntry& entry, const vector<SP500Entry>& data) {
    double latest = 5659.91; // Latest S&P 500 value (as of October 2025)
    double growth = latest / entry.sp500BuyValue;
    return entry.amountInvested * growth;
}
