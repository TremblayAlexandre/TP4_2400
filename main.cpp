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
    vector<unordered_map<string, string>> reservations;
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
        reservations.push_back(reservInfos);
    }

    file.close();
    return reservations;
}

int main() {
    // File paths for each sheet's CSV
    vector<string> sheets = {"ReservationsCSV/Vols.csv", "ReservationsCSV/Hebergement.csv", "ReservationsCSV/Excursions.csv"};

    vector<unordered_map<string, string>> vols = read_csv("ReservationsCSV/Vols.csv");
    vector<unordered_map<string, string>> hebergements = read_csv("ReservationsCSV/Hebergements.csv");
    vector<unordered_map<string, string>> excursions = read_csv("ReservationsCSV/Excursions.csv");

        auto print_reservations = [](const string &type, const vector<unordered_map<string, string>> &reservations) {
        cout << "==== " << type << " Reservations ====" << endl;
        for (const auto &reservation : reservations) {
            for (const auto &pair : reservation) {
                cout << pair.first << ": " << pair.second << endl;
            }
            cout << "--------------------------" << endl;
        }
    };

    // Print reservations for each category
    print_reservations("Vols", vols);
    print_reservations("Hebergements", hebergements);
    print_reservations("Excursions", excursions);
    return 0;
}