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
    vector<shared_ptr<Reservation>> sousReservations;  // Liste des sous-r�servations

public:
    // Constructeur
    GroupeReservation(const string& date, const string& contact, const string& email);

    // Destructeur
    virtual ~GroupeReservation();

    // M�thodes pour manipuler les sous-r�servations
    void ajouter(std::shared_ptr<Reservation> reservation);
    void supprimer(Reservation* reservation) override;
    Reservation* obtenirEnfant(int index) const override;

    // M�thodes sp�cifiques
    void afficherDetails() const override;  // Affiche les d�tails du groupe
    bool estGroupe() const override;       // Retourne true car c'est un groupe
};

#endif // GROUPERESERVATION_HPP
