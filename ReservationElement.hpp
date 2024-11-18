///////////////////////////////////////////////////////////
//  ReservationElement.h
//  Implementation of the Class ReservationElement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef RESERVATION_ELEMENT_HPP
#define RESERVATION_ELEMENT_HPP

#include <string>
#include <memory> // Pour std::shared_ptr
#include "ProxyOffreReservation.hpp"

namespace std {

    class ReservationElement {
    private:
        std::string contact;
        std::string vendeur;
        std::shared_ptr<string> dateAchat;
        std::shared_ptr<ProxyOffreReservation> proxyOffre;

    public:
        ReservationElement(const std::string& contact, const std::string& vendeur, std::shared_ptr<string> dateAchat, std::shared_ptr<ProxyOffreReservation> proxyOffre);
        void afficher() const;
        void ajouterReservation(const ReservationElement& reservation);
        void changerDate(const string& nouvelleDate);
        void changerDetails(const std::string& details);
        void changerNom(const std::string& nouveauNom);
        void supprimerReservation(const ReservationElement& reservation);
    };

} // namespace std

#endif // RESERVATION_ELEMENT_HPP
