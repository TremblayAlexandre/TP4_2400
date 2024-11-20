///////////////////////////////////////////////////////////
//  ReservationElement.cpp
//  Implementation of the Class ReservationElement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "ReservationElement.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

ReservationElement::ReservationElement(const string& date, const string& contact, const string& email, ProxyOffreReservation* offreAssociee)
    : Reservation(date, contact, email), offre(offreAssociee) {
    if (!offreAssociee) {
        throw invalid_argument("Le proxy de l'offre associ�e ne peut pas �tre nul.");
    }
}

ReservationElement::ReservationElement(const string& date, const string& contact, const string& email)
    : Reservation(date, contact, email), offre(nullptr) {
}

ReservationElement::~ReservationElement() {
}

ProxyOffreReservation* ReservationElement::getOffre() const {
    return offre;
}

void ReservationElement::afficherDetails() const {
    cout << "D�tails de la r�servation �l�mentaire :" << endl;
    cout << "Date de r�servation : " << getDateReservation() << endl;
    cout << "Contact vendeur : " << getContactVendeur() << endl;
    cout << "Email vendeur : " << getEmailVendeur() << endl;
}

void ReservationElement::ajouter(std::shared_ptr<Reservation> reservation) {
    throw logic_error("Op�ration non support�e pour une r�servation �l�mentaire.");
}

void ReservationElement::supprimer(Reservation* reservation) {
    throw logic_error("Op�ration non support�e pour une r�servation �l�mentaire.");
}

Reservation* ReservationElement::obtenirEnfant(int index) const {
    throw logic_error("Op�ration non support�e pour une r�servation �l�mentaire.");
}

bool ReservationElement::estGroupe() const {
    return false;
}
