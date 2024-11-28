///////////////////////////////////////////////////////////
//  GroupeReservation.h
//  Implementation of the Class GroupeReservation
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef GROUPERESERVATION_HPP
#define GROUPERESERVATION_HPP

#include "Reservation.hpp"
#include <vector>
#include <memory>

using namespace std;

class GroupeReservation : public Reservation {
private:
    vector<shared_ptr<Reservation>> sousReservations; 
    string titreReservation;

public:
    GroupeReservation(const string& titre, const string& nom, const string& date,
        const string& contact, const string& email, const bool estRacine=false);
    GroupeReservation(const GroupeReservation& autre, const string& nom);

    virtual ~GroupeReservation();

    void ajouter(std::shared_ptr<Reservation> reservation);
    void supprimer(Reservation* reservation) override;
    Reservation* obtenirEnfant(int index) const override;
    vector<shared_ptr<Reservation>> obtenirEnfants() const override;


   
    void afficherDetails() const override;
    bool estGroupe() const override;       
    double obtenirCouts() const override;
    string obtenirTitreReservation() const;

};

#endif // GROUPERESERVATION_HPP
