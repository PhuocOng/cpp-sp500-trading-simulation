#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void clean_sp500_csv(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        cerr << "Failed to open input file: " << inputFile << endl;
        return;
    }
    if (!outFile.is_open()) {
        cerr << "Failed to create output file: " << outputFile << endl;
        return;
    }

    string line;
    getline(inFile, line);  // Skip header

    outFile << "Date,Close\n";  // New header

    while (getline(inFile, line)) {
        stringstream ss(line);
        string date, close, open, high, low;

        getline(ss, date, ',');
        getline(ss, close, ',');
        getline(ss, open, ',');
        getline(ss, high, ',');
        getline(ss, low, ',');      // Low (ignored)

        outFile << date << "," << close << "\n";
    }

    inFile.close();
    outFile.close();
    cout << "Cleaned data written to: " << outputFile << endl;
}
