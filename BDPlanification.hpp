///////////////////////////////////////////////////////////
//  BDPlanification.h
//  Implementation of the Class BDPlanification
//  Created on:      17-Nov-2024 2:28:21 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef BDPLANIFICATION_HPP
#define BDPLANIFICATION_HPP
#pragma once

#include <vector>
#include <unordered_map>
#include "Reservation.hpp"

class BDPlanification {
private:
    BDPlanification() = default;
    static BDPlanification* instance;
    unordered_map<string, shared_ptr<Reservation>> reservations;

public:
    BDPlanification(const BDPlanification&) = delete;
    BDPlanification& operator=(const BDPlanification&) = delete;
    static BDPlanification* getInstance();
    ~BDPlanification() = default;

    void ajouterReservation(shared_ptr<Reservation> reservation);
    unordered_map<string, shared_ptr<Reservation>> obtenirReservations() const;
    shared_ptr<Reservation> rechercherReservation(const string& name) const;
    void supprimerReservation(shared_ptr<Reservation> reservation);
};

#endif // BDPLANIFICATION_HPP
