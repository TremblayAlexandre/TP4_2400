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
    : Reservation(nom,date, contact, email), titreReservation(titre){
    if (estRacine) {
        cout << titre << " de " << nom << " cree!" <<endl;
    }
}
GroupeReservation::GroupeReservation(const GroupeReservation& autre, const string& nom)
    : Reservation(autre),
    titreReservation(autre.titreReservation), sousReservations(autre.sousReservations){
    cout << titreReservation  <<" de " << nom << " copie a partir du " << autre.titreReservation <<" de " << autre.obtenirNomTitulaire() << "!" << endl;
}

GroupeReservation::~GroupeReservation() {}

void GroupeReservation::ajouter(std::shared_ptr<Reservation> reservation) {
    sousReservations.push_back(reservation);
    std::shared_ptr<GroupeReservation> groupeRes = std::dynamic_pointer_cast<GroupeReservation>(reservation);
    if (groupeRes) {
        cout << groupeRes.get()->obtenirTitreReservation() << " cree dans " << obtenirTitreReservation();
        cout << " de " << obtenirNomTitulaire() << endl;
    }
}

string GroupeReservation::obtenirTitreReservation() const {
    return titreReservation;
}


void GroupeReservation::supprimer(Reservation* reservation) {
    auto it = std::find_if(sousReservations.begin(), sousReservations.end(),
        [reservation](const std::shared_ptr<Reservation>& res) {
            return res.get() == reservation;
        });

    if (it != sousReservations.end()) {
        sousReservations.erase(it);
    }
    else {
        throw std::logic_error("La réservation à supprimer n'existe pas dans le groupe.");
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


void GroupeReservation::afficherDetails() const {
    cout << "Détails du groupe de réservations :" << endl;
    cout << "Date de réservation : " << obtenirDateReservation() << endl;
    cout << "Contact vendeur : " << obtenirContactVendeur() << endl;
    cout << "Email vendeur : " << obtenirEmailVendeur() << endl;
    cout << "Nombre de sous-réservations : " << sousReservations.size() << endl;

    for (const auto& reservation : sousReservations) {
        reservation->afficherDetails();
    }
}

double GroupeReservation::obtenirCouts() const {
    double total = 0.0;
    const auto& enfants = this->obtenirEnfants();
    for (const auto& enfant : enfants) {
        total += enfant->obtenirCouts();
    }
    return total;
}

bool GroupeReservation::estGroupe() const {
    return true;
}

