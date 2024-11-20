///////////////////////////////////////////////////////////
//  ReservationElement.h
//  Implementation of the Class ReservationElement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef RESERVATIONELEMENT_HPP
#define RESERVATIONELEMENT_HPP

#include "Reservation.hpp"
#include "ProxyOffreReservation.hpp"
#include <string>

using namespace std;

class ReservationElement : public Reservation {
private:
    ProxyOffreReservation* offre; 

public:
    ReservationElement(const string& date, const string& contact, const string& email, ProxyOffreReservation* offreAssociee);
    ReservationElement(const string& date, const string& contact, const string& email);

    virtual ~ReservationElement();

    ProxyOffreReservation* getOffre() const; 

    void afficherDetails() const override; 
    void ajouter(std::shared_ptr<Reservation> reservation) override;  // Non applicable pour une feuille
    void supprimer(Reservation* reservation) override; // Non applicable pour une feuille
    Reservation* obtenirEnfant(int index) const override; // Non applicable pour une feuille

    bool estGroupe() const override;
};

#endif // RESERVATION_ELEMENT_HPP
