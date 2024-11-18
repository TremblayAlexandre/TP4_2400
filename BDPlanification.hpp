///////////////////////////////////////////////////////////
//  BDPlanification.h
//  Implementation of the Class BDPlanification
//  Created on:      17-Nov-2024 2:28:21 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef BDPLANIFICATION_HPP
#define BDPLANIFICATION_HPP

#include <vector>
#include "Reservation.hpp"

class BDPlanification {
private:
    std::vector<Reservation> reservations;

public:
    void afficherReservations() const;
    void ajouterReservation(const Reservation& reservation);
    std::vector<Reservation> obtenirReservations() const;
    Reservation rechercherReservation(int index) const;
    void supprimerReservation(int index);
};

#endif // BDPLANIFICATION_HPP
