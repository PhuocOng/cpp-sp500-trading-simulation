#pragma once
#include <string>
#include <vector>
#include "sp500_data.h"
using namespace std;

struct PortfolioEntry {
    string buyDate;
    double amountInvested;
    double sp500BuyValue;
};

PortfolioEntry invest_in_sp500(const string& date, double amount, const vector<SP500Entry>& data);
double calculate_current_value(const PortfolioEntry& entry, const vector<SP500Entry>& data);
