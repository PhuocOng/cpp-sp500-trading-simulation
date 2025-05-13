#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct SP500Entry {
    string date;  // e.g., "01/30/2024"
    double close;      // e.g., 3900.12
};

vector<SP500Entry> parse_csv(const string& filename);
