#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <random>
#include <unordered_map>
#include "FabriqueOffreExcursion.hpp"
#include "FabriqueOffreHebergement.hpp"
#include "FabriqueOffreVol.hpp"

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


string generateUUID() {
    // Random number generators
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<uint32_t> dist(0, 0xFFFFFFFF);

    // Generate random values for each part of the UUID
    uint32_t part1 = dist(gen);
    uint16_t part2 = (dist(gen) & 0xFFFF);
    uint16_t part3 = (dist(gen) & 0x0FFF) | 0x4000; // Set version to 4
    uint16_t part4 = (dist(gen) & 0x3FFF) | 0x8000; // Set variant to 10xx
    uint64_t part5 = (static_cast<uint64_t>(dist(gen)) << 32) | dist(gen);

    // Format the UUID as a string
    ostringstream oss;
    oss << hex << setfill('0')
        << setw(8) << part1 << "-"
        << setw(4) << part2 << "-"
        << setw(4) << part3 << "-"
        << setw(4) << part4 << "-"
        << setw(12) << part5;

    return oss.str();
}

int main() {
    // File paths for each sheet's CSV

    vector<unordered_map<string, string>> vols = read_csv("OffresCSV/Vols.csv");
    vector<unordered_map<string, string>> hebergements = read_csv("OffresCSV/Hebergements.csv");
    vector<unordered_map<string, string>> excursions = read_csv("OffresCSV/Excursions.csv");

        auto afficher_offres = [](const string &type, const vector<unordered_map<string, string>> &offres) {
        cout << "==== " << type << " Offres ====" << endl;
        for (const auto &offre : offres) {
            for (const auto &pair : offre) {
                cout << pair.first << ": " << pair.second << endl;
            }
            cout << "--------------------------" << endl;
        }
    };

     //afficher offres for each category
     afficher_offres("Vols", vols);
     afficher_offres("Hebergements", hebergements);
     afficher_offres("Excursions", excursions);
    FabriqueOffreVol fabVol = FabriqueOffreVol(); 
    for(unordered_map<string, string> offre : vols){
        fabVol.creerOffre(generateUUID(), offre);
    }
    FabriqueOffreExcursion fabExc = FabriqueOffreExcursion();
    for (unordered_map<string, string> offre : excursions) {
        fabExc.creerOffre(generateUUID(), offre);
    }
    FabriqueOffreHebergement fabHeb = FabriqueOffreHebergement();
    for (unordered_map<string, string> offre : hebergements) {
        fabHeb.creerOffre(generateUUID(), offre);
    }
    
    return 0;
}