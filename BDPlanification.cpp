///////////////////////////////////////////////////////////
//  BDPlanification.cpp
//  Implementation of the Class BDPlanification
//  Created on:      17-Nov-2024 2:28:21 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "BDPlanification.hpp"
#include <iostream>



void BDPlanification::ajouterReservation(shared_ptr<Reservation> reservation) {
    this->reservations[reservation->obtenirTitreReservation()] = reservation;
}

unordered_map<string, shared_ptr<Reservation>> BDPlanification::obtenirReservations() const {
    return reservations;
}


shared_ptr<Reservation> BDPlanification::rechercherReservation(const string& name) const {
    if (this->reservations.contains(name)) return reservations.at(name);

    return nullptr;
}

void BDPlanification::supprimerReservation(shared_ptr<Reservation> reservation) {
    this->reservations.erase(reservation->obtenirTitreReservation());
}
