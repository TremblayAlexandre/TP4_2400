#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<unordered_map<string, string>> read_csv(const string &file_path) {
    ifstream file(file_path);

    if (!file.is_open()) {
        cerr << "Error opening file: " << file_path << endl;
        return {};
    }

    string line;
    vector<string> headers;

    // Read the header row (column names)
    if (getline(file, line)) {
        stringstream ss(line);
        string column_name;

        while (getline(ss, column_name, ',')) {
            headers.push_back(column_name);
        }
    }

    // Read the rest of the rows
    vector<unordered_map<string, string>> offres;
    while (getline(file, line)) {
        unordered_map<string, string> reservInfos;
        stringstream ss(line);
        string cell;
        size_t col_index = 0;

        while (getline(ss, cell, ',')) {
            if (col_index < headers.size()) {
                reservInfos[headers[col_index]] = cell;
            }
            col_index++;
        }
        offres.push_back(reservInfos);
    }

    file.close();
    return offres;
}

int main() {
    // File paths for each sheet's CSV

    vector<unordered_map<string, string>> vols = read_csv("OffresCSV/Vols.csv");
    vector<unordered_map<string, string>> hebergements = read_csv("OffresCSV/Hebergements.csv");
    vector<unordered_map<string, string>> excursions = read_csv("OffresCSV/Excursions.csv");

        auto print_offres = [](const string &type, const vector<unordered_map<string, string>> &offres) {
        cout << "==== " << type << " Offres ====" << endl;
        for (const auto &offre : offres) {
            for (const auto &pair : offre) {
                cout << pair.first << ": " << pair.second << endl;
            }
            cout << "--------------------------" << endl;
        }
    };

    // Print offres for each category
    print_offres("Vols", vols);
    print_offres("Hebergements", hebergements);
    print_offres("Excursions", excursions);
    return 0;
}