///////////////////////////////////////////////////////////
//  GroupeReservation.cpp
//  Implementation of the Class GroupeReservation
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "GroupeReservation.hpp"
#include <algorithm>

namespace std {

    void GroupeReservation::afficher() const {
        for (const auto& reservation : reservations) {
            reservation.afficher(); 
        }
    }

    void GroupeReservation::ajouterReservation(const ReservationElement& reservation) {
        reservations.push_back(reservation);
    }

    void GroupeReservation::changerDate(const std::string& nouvelleDate) {
        for (auto& reservation : reservations) {
            reservation.changerDate(nouvelleDate); 
        }
    }

    void GroupeReservation::changerDetails(const std::string& details) {
        for (auto& reservation : reservations) {
            reservation.changerDetails(details); 
        }
    }

    void GroupeReservation::changerNom(const std::string& nouveauNom) {
        for (auto& reservation : reservations) {
            reservation.changerNom(nouveauNom); 
        }
    }

    void GroupeReservation::supprimerReservation(const ReservationElement& reservation) {
        reservations.erase(
            std::remove(reservations.begin(), reservations.end(), reservation),
            reservations.end()
        );
    }

} // namespace std
