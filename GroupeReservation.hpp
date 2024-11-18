///////////////////////////////////////////////////////////
//  GroupeReservation.h
//  Implementation of the Class GroupeReservation
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef GROUPE_RESERVATION_HPP
#define GROUPE_RESERVATION_HPP

#include <vector>
#include "ReservationElement.hpp"

namespace std {

    class GroupeReservation {
    private:
        std::vector<ReservationElement> reservations;

    public:
        void afficher() const;
        void ajouterReservation(const ReservationElement& reservation);
        void changerDate(const string& nouvelleDate);
        void changerDetails(const std::string& details);
        void changerNom(const std::string& nouveauNom);
        void supprimerReservation(const ReservationElement& reservation);
    };

} // namespace std

#endif // GROUPE_RESERVATION_HPP
