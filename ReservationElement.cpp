///////////////////////////////////////////////////////////
//  ReservationElement.cpp
//  Implementation of the Class ReservationElement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "ReservationElement.hpp"

namespace std {

    ReservationElement::ReservationElement(const std::string& contact, const std::string& vendeur, std::shared_ptr<string> dateAchat, std::shared_ptr<ProxyOffreReservation> proxyOffre)
        : contact(contact), vendeur(vendeur), dateAchat(dateAchat), proxyOffre(proxyOffre) {
        // Initialisation des membres
    }

    void ReservationElement::afficher() const {
        // Impl�mentation � venir
    }

    void ReservationElement::ajouterReservation(const ReservationElement& reservation) {
        // Impl�mentation � venir
    }

    void ReservationElement::changerDate(const string& nouvelleDate) {
        // Impl�mentation � venir
    }

    void ReservationElement::changerDetails(const std::string& details) {
        // Impl�mentation � venir
    }

    void ReservationElement::changerNom(const std::string& nouveauNom) {
        // Impl�mentation � venir
    }

    void ReservationElement::supprimerReservation(const ReservationElement& reservation) {
        // Impl�mentation � venir
    }

} // namespace std
