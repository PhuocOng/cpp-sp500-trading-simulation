#include "sp500_data.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;


vector<SP500Entry> parse_csv(const string& filename) {
    vector<SP500Entry> data;
    ifstream file(filename);
    string line;

    // Skip header
    getline(file, line);

    while (getline(file, line)) {
        istringstream ss(line);
        string date, closeStr;
        if (getline(ss, date, ',') && getline(ss, closeStr)) {
            SP500Entry entry{date, stod(closeStr)};
            data.push_back(entry);
        }
    }

    return data;
}
