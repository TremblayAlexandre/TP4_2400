///////////////////////////////////////////////////////////
//  Reservation.cpp
//  Implementation of the Class Reservation
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "Reservation.hpp"
#include <iostream>

using namespace std;

Reservation::Reservation(const string& date, const string& contact, const string& email)
    : dateReservation(date), contactVendeur(contact), emailVendeur(email) {}

Reservation::~Reservation() {}

string Reservation::getDateReservation() const {
    return dateReservation;
}

string Reservation::getContactVendeur() const {
    return contactVendeur;
}

string Reservation::getEmailVendeur() const {
    return emailVendeur;
}

void Reservation::ajouter(std::shared_ptr<Reservation> reservation) {
    throw logic_error("Opération non supportée pour une réservation individuelle.");
}

void Reservation::supprimer(Reservation* reservation) {
    throw logic_error("Opération non supportée pour une réservation individuelle.");
}

Reservation* Reservation::obtenirEnfant(int index) const {
    throw logic_error("Opération non supportée pour une réservation individuelle.");
}

