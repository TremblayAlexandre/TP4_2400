///////////////////////////////////////////////////////////
//  GroupeReservation.cpp
//  Implementation of the Class GroupeReservation
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////


#include "GroupeReservation.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

GroupeReservation::GroupeReservation(const string& date, const string& contact, const string& email)
    : Reservation(date, contact, email) {}

GroupeReservation::~GroupeReservation() {}

void GroupeReservation::ajouter(std::shared_ptr<Reservation> reservation) {
    sousReservations.push_back(reservation);
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

void GroupeReservation::afficherDetails() const {
    cout << "Détails du groupe de réservations :" << endl;
    cout << "Date de réservation : " << getDateReservation() << endl;
    cout << "Contact vendeur : " << getContactVendeur() << endl;
    cout << "Email vendeur : " << getEmailVendeur() << endl;
    cout << "Nombre de sous-réservations : " << sousReservations.size() << endl;

    for (const auto& reservation : sousReservations) {
        reservation->afficherDetails();
    }
}

bool GroupeReservation::estGroupe() const {
    return true;
}

