///////////////////////////////////////////////////////////
//  Reservation.cpp
//  Implementation of the Class Reservation
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "Reservation.hpp"
#include <iostream>

using namespace std;

Reservation::Reservation(const string& nom,const string& date, const string& contact, const string& email)
    : dateReservation(date),
    contactVendeur(contact),
    emailVendeur(email),
    nomTitulaire(nom),
    aParent(false) {
    titreReservation = "";
}

Reservation::Reservation(const Reservation& autre) : dateReservation(autre.dateReservation),
    contactVendeur(autre.contactVendeur),
    emailVendeur(autre.emailVendeur),
    nomTitulaire(autre.nomTitulaire),
    aParent(autre.aParent), titreReservation(autre.titreReservation) {
}


Reservation::~Reservation() {}

string Reservation::obtenirNomTitulaire() const {
    return nomTitulaire;
}

string Reservation::obtenirDateReservation() const {
    return dateReservation;
}

string Reservation::obtenirContactVendeur() const {
    return contactVendeur;
}

string Reservation::obtenirEmailVendeur() const {
    return emailVendeur;
}
string Reservation::obtenirTitreReservation() const {
    return titreReservation;
}


void Reservation::definirParent(Reservation* grpReservation) {
    parent = grpReservation;
}
Reservation* Reservation::obtenirParent(Reservation* grpReservation) {
    if (obtenirAParent()) {
        return parent;
    }
    return nullptr;
}
bool Reservation::obtenirAParent() {
    return aParent;
}

void Reservation::definirTitreReservation(const string& titre) {
    titreReservation = titre;
}
void Reservation::definirTitulaire(const string& nom) {
    nomTitulaire = nom;
}
