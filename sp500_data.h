#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct SP500Entry {
    std::string date;  // e.g., "2023-01-01"
    double close;      // e.g., 3900.12
};

std::vector<SP500Entry> parse_csv(const std::string& filename);
