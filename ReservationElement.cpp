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

ReservationElement::ReservationElement(const string& nom, const string& date, const string& contact, const string& email, shared_ptr<ProxyOffreReservation> offreAssociee)
    : Reservation(nom, date, contact, email), offre(offreAssociee) {
    if (!offreAssociee) {
        throw invalid_argument("Le proxy de l'offre associée ne peut pas être nul.");
    }
    cout << "         ";
    cout << "Reservation creee : ";
    cout << "Voyage de " << obtenirNomTitulaire() << "/";
    cout << obtenirDateReservation() << "/";
    cout << offre->obtenirNom() << endl;
    definirTitreReservation("Voyage de " + nom);
}

ReservationElement::~ReservationElement() {
}

string ReservationElement::obtenirTitreReservation() const {
    return offre->obtenirNom();
};


double ReservationElement::obtenirCouts(const string& autredevise = "CAD", double taxe = 1.0) const {
    return offre->calculerPrixTotal(autredevise, taxe); 
}

string ReservationElement::obtenirDetails() const {
    string details = "      ";
    details += "Reservation " + offre->obtenirNom();
    details += +", prix total ($ CA): " + to_string(static_cast<int>(round(offre->calculerPrixTotal())));
    details += ".\n";
    if (offre->obtenirCommentaire().length() > 0) {
    details += "        Commentaire: " + offre->obtenirCommentaire() + "\n";
    }
    return details;
}

void ReservationElement::ajouter(std::shared_ptr<Reservation> reservation) {
    throw logic_error("Opération non supportée pour une réservation élémentaire.");
}

void ReservationElement::supprimer(const string& titre) {
    throw logic_error("Opération non supportée pour une réservation élémentaire.");
}

Reservation* ReservationElement::obtenirEnfant(int index) const {
    throw logic_error("Opération non supportée pour une réservation élémentaire.");
}

vector<shared_ptr<Reservation>> ReservationElement::obtenirEnfants() const {
    throw logic_error("Opération non supportée pour une réservation élémentaire.");
}
std::shared_ptr<Reservation> ReservationElement::clone(const string& nouvNom) const {
    shared_ptr<Reservation> temp = make_shared<ReservationElement>(*this);
    return temp;
}
bool ReservationElement::estGroupe() const {
    return false;
}
