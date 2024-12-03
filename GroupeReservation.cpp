///////////////////////////////////////////////////////////
//  GroupeReservation.cpp
//  Implementation of the Class GroupeReservation
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////


#include "GroupeReservation.hpp"
#include <iostream>
#include <algorithm>
#include <typeinfo>

using namespace std;

GroupeReservation::GroupeReservation(const string& titre, const string& nom, const string& date, const string& contact, const string& email, const bool estRacine)
    : Reservation(nom,date, contact, email){
    definirTitreReservation(titre);
    if (estRacine) {
        cout << titre << " cree!" <<endl;
    }
}
GroupeReservation::GroupeReservation(const GroupeReservation& autre, const string& nom)
    : Reservation(autre)
{
    definirTitulaire(nom);
    string titre = autre.obtenirTitreReservation();
    size_t pos = titre.find(' ');
    string firstWord = (pos == std::string::npos) ? titre : titre.substr(0, pos);

    if (firstWord == "Voyage") titre = nom =="Alicia" ? "Voyage d'" + nom : "Voyage de " + nom;
    definirTitreReservation(titre);
    cout << obtenirTitreReservation() << " copie a partir du " << autre.obtenirTitreReservation() << "!" << endl;

    // Effectuer une copie profonde des sous-réservations
    for (const auto& res : autre.sousReservations) {
        sousReservations.push_back(res->clone(nom));
    }
}

GroupeReservation::~GroupeReservation() {}

void GroupeReservation::ajouter(std::shared_ptr<Reservation> reservation) {
    if (sousReservations.empty()) {
        sousReservations.push_back(reservation);
    }
    else {
        const string date = reservation->obtenirDateReservation();
        bool inserer = false;

        for (size_t i = 0; i < sousReservations.size(); ++i) {
            string dateActuelle = sousReservations[i]->obtenirDateReservation();

            if (date < dateActuelle) {
                // Insérer avant la réservation actuelle
                sousReservations.insert(sousReservations.begin() + i, reservation);
                inserer = true;
                break;
            }
            else if (date == dateActuelle) {
                // Trouver la dernière réservation avec la même date
                size_t j = i;
                while (j < sousReservations.size() && sousReservations[j]->obtenirDateReservation() == date) {
                    ++j;
                }
                // Insérer après toutes les réservations ayant la même date
                sousReservations.insert(sousReservations.begin() + j, reservation);
                inserer = true;
                break;
            }
        }

        if (!inserer) {
            // Si la nouvelle date est après toutes les dates existantes, ajouter à la fin
            sousReservations.push_back(reservation);
        }
    }

    std::shared_ptr<GroupeReservation> groupeRes = std::dynamic_pointer_cast<GroupeReservation>(reservation);
    if (groupeRes) {
        const string titre = groupeRes->obtenirTitreReservation();
        size_t pos = titre.find(' ');
        string firstWord = (pos == std::string::npos) ? titre : titre.substr(0, pos);
        string parentTitre = obtenirTitreReservation();
        size_t pos2 = parentTitre.rfind(' ');
        string lastWord = (pos2 == std::string::npos) ? parentTitre : parentTitre.substr(pos2 + 1);
        if (firstWord == "Journee") cout << "      ";
        else if (firstWord == "Segment") cout << "   ";
        cout << groupeRes->obtenirTitreReservation() << " cree dans le " << obtenirTitreReservation();
        //if (!(lastWord == obtenirNomTitulaire())) cout << " de " << obtenirNomTitulaire();
        cout << "!" << endl;
    }
}







Reservation* GroupeReservation::obtenirEnfant(int index) const {
    if (index < 0 || index >= static_cast<int>(sousReservations.size())) {
        throw out_of_range("Index hors des limites.");
    }
    return sousReservations[index].get();
}
vector<shared_ptr<Reservation>> GroupeReservation::obtenirEnfants() const {
    return (this->sousReservations);
}

void GroupeReservation::supprimer(const string& titre) {
    for (auto it = sousReservations.begin(); it != sousReservations.end(); ++it) {
        if ((*it)->obtenirTitreReservation() == titre) {
            cout << "   " <<(*it)->obtenirTitreReservation() << " efface!" << endl;
            sousReservations.erase(it);
            break;
        }
    }
}

string GroupeReservation::obtenirDetails() const {
    string details = "";
    const string titre = obtenirTitreReservation();
    size_t pos = titre.find(' ');
    string firstWord = (pos == std::string::npos) ? titre : titre.substr(0, pos);
    if (firstWord == "Journee") details += "   ";
    details += titre + "\n";
    if (firstWord == "Segment") details = "";

    for (const auto& reservation : sousReservations) {
       details += reservation->obtenirDetails();
    }
    return details;
}

double GroupeReservation::obtenirCouts(const string& autredevise = "CAD", double taxe = 1.0) const {
    double total = 0.0;
    const auto& enfants = this->obtenirEnfants();
    for (const auto& enfant : enfants) {
        total += enfant->obtenirCouts(autredevise, taxe);
    }
    return total;
}

std::shared_ptr<Reservation> GroupeReservation::clone(const string& nouvNom) const {
    shared_ptr<Reservation> temp = make_shared<GroupeReservation>(*this); 
    temp->definirTitulaire(nouvNom);
    return temp;
}

bool GroupeReservation::estGroupe() const {
    return true;
}

