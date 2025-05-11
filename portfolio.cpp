#include "portfolio.h"
#include <iostream>

PortfolioEntry invest_in_sp500(const std::string& date, double amount, const std::vector<SP500Entry>& data) {
    for (const auto& entry : data) {
        if (entry.date == date) {
            return {date, amount, entry.close};
        }
    }
    throw std::runtime_error("Buy date not found in data");
}

double calculate_current_value(const PortfolioEntry& entry, const std::vector<SP500Entry>& data) {
    double latest = data.back().close;
    double growth = latest / entry.sp500BuyValue;
    return entry.amountInvested * growth;
}
