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
#include "BDOReservation.hpp"
#include "BDPlanification.hpp"
#include "GroupeReservation.hpp"
#include "ReservationElement.hpp"

using namespace std;

string NOM_CONTACT = "Massil";
string EMAIL_CONTACT = "Massil@polyvoyage.com";
string DORA_NOM = "Dora";
string DIEGO_NOM = "Diego";
string ALICIA_NOM = "Alicia";


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


void reservationsScript(BDOReservation BDOR) {
    BDPlanification BDP = BDPlanification();
    cout << endl; // Pour séparer de la section en haut
    shared_ptr<GroupeReservation> voyageDoraPtr = make_shared<GroupeReservation>(
        "Voyage de Dora", DORA_NOM, "2024-10-26", NOM_CONTACT, EMAIL_CONTACT, true);
    { // SEGMENT FRANCE 1 DORA
        shared_ptr<GroupeReservation> segment1Dora = make_shared<GroupeReservation>("Segment France 1ère partie", DORA_NOM, "2024-10-26",
            NOM_CONTACT, EMAIL_CONTACT);
        voyageDoraPtr->ajouter(segment1Dora);
        { // JOURNEE 1
        shared_ptr<GroupeReservation> journee1Seg1 = make_shared<GroupeReservation>("Journee 2024-10-26", DORA_NOM, "2024-10-26",
            NOM_CONTACT, EMAIL_CONTACT);
        segment1Dora->ajouter(journee1Seg1);
        shared_ptr<ProxyOffreReservation>  proxy1Jour1 = BDOR.trouverOffreParNom("Air Canada AC 870 2024-10-26")->reserver();
        ReservationElement reserv1Jour1 = ReservationElement(DORA_NOM,
            "2024-10-26", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour1);
        journee1Seg1->ajouter(make_shared<ReservationElement>(reserv1Jour1));
        }
        { // JOURNEE 2 
            shared_ptr<GroupeReservation> journee2Seg1 = make_shared<GroupeReservation>("Journee 2024-10-27", DORA_NOM, "2024-10-27",
                NOM_CONTACT, EMAIL_CONTACT);
            segment1Dora->ajouter(journee2Seg1);
            shared_ptr<ProxyOffreReservation> proxy1Jour2 = BDOR.trouverOffreParNom("Hotel Stella")->reserver();
            ReservationElement reserv1Jour2 = ReservationElement(DORA_NOM,
                "2024-10-27", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour2);
            journee2Seg1->ajouter(make_shared<ReservationElement>(reserv1Jour2));

        }
        
        { // JOURNEE 3 DORA
            shared_ptr<GroupeReservation> journee3Seg1 = make_shared<GroupeReservation>("Journee 2024-10-28", DORA_NOM, "2024-10-28",
                NOM_CONTACT, EMAIL_CONTACT);
            segment1Dora->ajouter(journee3Seg1);
            //cout << BDOR.trouverOffreParNom("Paris Diner-croisiere sur la Seine by Bateaux Mouches")->obtenirNom();
            shared_ptr<ProxyOffreReservation> proxy1Jour3 = BDOR.trouverOffreParNom("Paris Diner-croisiere sur la Seine by Bateaux Mouches")->reserver();
            shared_ptr<ProxyOffreReservation> proxy2Jour3 = BDOR.trouverOffreParNom("Hotel Stella")->reserver();
            ReservationElement reserv1Jour3 = ReservationElement(DORA_NOM,
                "2024-10-28", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour3);
            ReservationElement reserv2Jour3 = ReservationElement(DORA_NOM,
                "2024-10-28", NOM_CONTACT, EMAIL_CONTACT, proxy2Jour3);
            journee3Seg1->ajouter(make_shared<ReservationElement>(reserv1Jour3));
            journee3Seg1->ajouter(make_shared<ReservationElement>(reserv2Jour3));
        }
        
    }
    { // SEGMENT PORTUGAL
        shared_ptr<GroupeReservation> segment2Dora = make_shared<GroupeReservation>("Segment Portugal", DORA_NOM, "2024-10-29",
            NOM_CONTACT, EMAIL_CONTACT);
        voyageDoraPtr->ajouter(segment2Dora);
        { // JOURNEE 1
            shared_ptr<GroupeReservation> journee1Seg2 = make_shared<GroupeReservation>("Journee 2024-10-29", DORA_NOM, "2024-10-29",
                NOM_CONTACT, EMAIL_CONTACT);
            segment2Dora->ajouter(journee1Seg2);
            shared_ptr<ProxyOffreReservation> proxy1Jour1 = BDOR.trouverOffreParNom(
            "TAP Air Portugal TP 0441 2024-10-29")->reserver();
            ReservationElement reserv1Jour1 = ReservationElement(DORA_NOM,
                "2024-10-29", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour1);
            shared_ptr<ProxyOffreReservation> proxy1Jour2 = make_shared<ProxyOffreReservation>(BDOR.trouverOffreParNom("Hotel Roma"));
            ReservationElement reserv2Jour1 = ReservationElement(DORA_NOM,
                "2024-10-29", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour2);
            journee1Seg2->ajouter(make_shared<ReservationElement>(reserv1Jour1));
            journee1Seg2->ajouter(make_shared<ReservationElement>(reserv2Jour1));

        }
        { // JOURNEE 2
            shared_ptr<GroupeReservation> journee2Seg2 = make_shared<GroupeReservation>("Journee 2024-10-30", DORA_NOM, "2024-10-30",
                NOM_CONTACT, EMAIL_CONTACT);
            segment2Dora->ajouter(journee2Seg2);
            shared_ptr<ProxyOffreReservation> proxy1Jour2 = BDOR.trouverOffreParNom("Visite du Musee Calouste")->reserver();
            ReservationElement reserv1Jour2 = ReservationElement(DORA_NOM,
                "2024-10-30", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour2);
            shared_ptr<ProxyOffreReservation> proxy2Jour2 = BDOR.trouverOffreParNom("Hotel Roma")->reserver();
            ReservationElement reserv2Jour2 = ReservationElement(DORA_NOM,
                "2024-10-30", NOM_CONTACT, EMAIL_CONTACT, proxy2Jour2);
            journee2Seg2->ajouter(make_shared<ReservationElement>(reserv1Jour2));
            journee2Seg2->ajouter(make_shared<ReservationElement>(reserv2Jour2));


        }
        { // JOURNEE 3
            shared_ptr<GroupeReservation> journee3Seg2 = make_shared<GroupeReservation>("Journee 2024-10-31", DORA_NOM, "2024-10-31",
                NOM_CONTACT, EMAIL_CONTACT);
            segment2Dora->ajouter(journee3Seg2);
            //cout << BDOR.trouverOffreParNom("Paris Diner-croisiere sur la Seine by Bateaux Mouches")->obtenirNom();
            shared_ptr<ProxyOffreReservation> proxy1Jour3 = BDOR.trouverOffreParNom("easyJet 4592 2024-10-31")->reserver();
            ReservationElement reserv1Jour3 = ReservationElement(DORA_NOM,
                "2024-10-28", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour3);
            journee3Seg2->ajouter(make_shared<ReservationElement>(reserv1Jour3));

        }

    }
    { // SEGMENT FRANCE 2
        shared_ptr<GroupeReservation> segment3Dora = make_shared<GroupeReservation>("Segment France 2e partie", DORA_NOM, "2024-10-31",
            NOM_CONTACT, EMAIL_CONTACT);
        voyageDoraPtr->ajouter(segment3Dora);
        { // JOURNEE 1
            shared_ptr<GroupeReservation> journee1Seg3 = make_shared<GroupeReservation>("Journee 2024-10-31", DORA_NOM, "2024-10-31",
                NOM_CONTACT, EMAIL_CONTACT);
            segment3Dora->ajouter(journee1Seg3);
            shared_ptr<ProxyOffreReservation> proxy1Jour1 = BDOR.trouverOffreParNom("Hotel Stella")->reserver();
            ReservationElement reserv1Jour1 = ReservationElement(DORA_NOM,
                "2024-10-31", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour1);
            journee1Seg3->ajouter(make_shared<ReservationElement>(reserv1Jour1));

        }
        { // JOURNEE 2
            shared_ptr<GroupeReservation> journee2Seg3 = make_shared<GroupeReservation>("Journee 2024-11-01", DORA_NOM, "2024-11-01",
                NOM_CONTACT, EMAIL_CONTACT);
            segment3Dora->ajouter(journee2Seg3);
            shared_ptr<ProxyOffreReservation> proxy1Jour2 = BDOR.trouverOffreParNom("Visite guidee pour voir les chefs")->reserver();
            ReservationElement reserv1Jour2 = ReservationElement(DORA_NOM,
                "2024-11-01", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour2);
            shared_ptr<ProxyOffreReservation> proxy2Jour2 = BDOR.trouverOffreParNom("Hotel Stella")->reserver();
            ReservationElement reserv2Jour2 = ReservationElement(DORA_NOM,
                "2024-11-01", NOM_CONTACT, EMAIL_CONTACT, proxy2Jour2);
            journee2Seg3->ajouter(make_shared<ReservationElement>(reserv1Jour2));
            journee2Seg3->ajouter(make_shared<ReservationElement>(reserv2Jour2));


        }
        { // JOURNEE 3
            shared_ptr<GroupeReservation> journee3Seg3 = make_shared<GroupeReservation>("Journee 2024-11-02", DORA_NOM, "2024-11-02",
                NOM_CONTACT, EMAIL_CONTACT);
            segment3Dora->ajouter(journee3Seg3);
            //cout << BDOR.trouverOffreParNom("Paris Diner-croisiere sur la Seine by Bateaux Mouches")->obtenirNom();
            shared_ptr<ProxyOffreReservation> proxy1Jour3 = BDOR.trouverOffreParNom("Visite guidee a Versailles et")->reserver();
            shared_ptr<ProxyOffreReservation> proxy2Jour3 = BDOR.trouverOffreParNom("Hotel Stella")->reserver();
            ReservationElement reserv1Jour3 = ReservationElement(DORA_NOM,
                "2024-11-02", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour3);
            ReservationElement reserv2Jour3 = ReservationElement(DORA_NOM,
                "2024-11-02", NOM_CONTACT, EMAIL_CONTACT, proxy2Jour3);
            journee3Seg3->ajouter(make_shared<ReservationElement>(reserv1Jour3));
            journee3Seg3->ajouter(make_shared<ReservationElement>(reserv2Jour3));

        }
        { // JOURNEE 4
            shared_ptr<GroupeReservation> journee4Seg3 = make_shared<GroupeReservation>("Journee 2024-11-03", DORA_NOM, "2024-11-03",
                NOM_CONTACT, EMAIL_CONTACT);
            segment3Dora->ajouter(journee4Seg3);
            shared_ptr<ProxyOffreReservation> proxy1Jour4 = BDOR.trouverOffreParNom("Air Transat 111 2024-11-03")->reserver();
            ReservationElement reserv1Jour4 = ReservationElement(DORA_NOM,
                "2024-11-03", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour4);
            journee4Seg3->ajouter(make_shared<ReservationElement>(reserv1Jour4));

        }

    }
    cout << endl;
    shared_ptr<GroupeReservation> voyageDiegoPtr = make_shared<GroupeReservation>(*voyageDoraPtr, DIEGO_NOM);
    
    voyageDiegoPtr->supprimer("Segment Portugal");
    { // SEGMENT FRANCE 1 DIEGO
        shared_ptr<GroupeReservation> segment1Diego = make_shared<GroupeReservation>("Segment Espagne", DIEGO_NOM, "2024-10-29",
            NOM_CONTACT, EMAIL_CONTACT);
        voyageDiegoPtr->ajouter(segment1Diego);
        { // JOURNEE 1
            shared_ptr<GroupeReservation> journee1Seg1 = make_shared<GroupeReservation>("Journee 2024-10-29", DIEGO_NOM, "2024-10-29",
                NOM_CONTACT, EMAIL_CONTACT);
            segment1Diego->ajouter(journee1Seg1);
            shared_ptr<ProxyOffreReservation>  proxy1Jour1 = BDOR.trouverOffreParNom("Air Europa 1026")->reserver();
            ReservationElement reserv1Jour1 = ReservationElement(DIEGO_NOM,
                "2024-10-29", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour1);
            shared_ptr<ProxyOffreReservation>  proxy2Jour1 = BDOR.trouverOffreParNom("Far Home Atocha")->reserver();
            ReservationElement reserv2Jour1 = ReservationElement(DIEGO_NOM,
                "2024-10-29", NOM_CONTACT, EMAIL_CONTACT, proxy2Jour1);
            journee1Seg1->ajouter(make_shared<ReservationElement>(reserv1Jour1));
            journee1Seg1->ajouter(make_shared<ReservationElement>(reserv2Jour1));

        }
        { // JOURNEE 2
            shared_ptr<GroupeReservation> journee2Seg1 = make_shared<GroupeReservation>("Journee 2024-10-30", DIEGO_NOM, "2024-10-30",
                NOM_CONTACT, EMAIL_CONTACT);
            segment1Diego->ajouter(journee2Seg1);
            shared_ptr<ProxyOffreReservation>  proxy1Jour2 = BDOR.trouverOffreParNom("Excursion d'une journ")->reserver();
            ReservationElement reserv1Jour2 = ReservationElement(DIEGO_NOM,
                "2024-10-30", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour2);
            shared_ptr<ProxyOffreReservation>  proxy2Jour2 = BDOR.trouverOffreParNom("Far Home Atocha")->reserver();
            ReservationElement reserv2Jour2 = ReservationElement(DIEGO_NOM,
                "2024-10-30", NOM_CONTACT, EMAIL_CONTACT, proxy2Jour2);
            journee2Seg1->ajouter(make_shared<ReservationElement>(reserv1Jour2));
            journee2Seg1->ajouter(make_shared<ReservationElement>(reserv2Jour2));

        }
        { // JOURNEE 3
            shared_ptr<GroupeReservation> journee3Seg1 = make_shared<GroupeReservation>("Journee 2024-10-31", DIEGO_NOM, "2024-10-31",
                NOM_CONTACT, EMAIL_CONTACT);
            segment1Diego->ajouter(journee3Seg1);
            shared_ptr<ProxyOffreReservation>  proxy1Jour3 = BDOR.trouverOffreParNom("Air Europa 1025")->reserver();
            ReservationElement reserv1Jour3 = ReservationElement(DIEGO_NOM,
                "2024-10-31", NOM_CONTACT, EMAIL_CONTACT, proxy1Jour3);
            journee3Seg1->ajouter(make_shared<ReservationElement>(reserv1Jour3));

        }
    }
    cout << endl;
    shared_ptr<GroupeReservation> voyageAliciaPtr = make_shared<GroupeReservation>(*voyageDiegoPtr, ALICIA_NOM);

    cout << endl;

    BDP.ajouterReservation(voyageDoraPtr);
    BDP.ajouterReservation(voyageDiegoPtr);
    BDP.ajouterReservation(voyageAliciaPtr);
    for (const auto& res : BDP.obtenirReservations()) {
        cout << "Total des frais pour le ";
        cout << res.second->obtenirTitreReservation();
        cout << " ($ CA): ";
        cout << res.second->obtenirCouts() << endl;
    }
}

int main() {

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
     //afficher_offres("Vols", vols);
     //afficher_offres("Hebergements", hebergements);
     //afficher_offres("Excursions", excursions);

    BDOReservation BDOR = BDOReservation();

    FabriqueOffreVol fabVol = FabriqueOffreVol(); 
    for(unordered_map<string, string> offre : vols){
        shared_ptr<OffreVol> vol = fabVol.creerOffre(generateUUID(), offre);
        BDOR.ajouterOffre(vol);
    }
    FabriqueOffreHebergement fabHeb = FabriqueOffreHebergement();
    for (unordered_map<string, string> offre : hebergements) {
        shared_ptr<OffreHebergement> hebergement = fabHeb.creerOffre(generateUUID(), offre);
        BDOR.ajouterOffre(hebergement);
    }
    FabriqueOffreExcursion fabExc = FabriqueOffreExcursion();
    for (unordered_map<string, string> offre : excursions) {
        shared_ptr<OffreExcursion> excursion = fabExc.creerOffre(generateUUID(), offre);
        BDOR.ajouterOffre(excursion);
    }

    reservationsScript(BDOR);

    return 0;
}