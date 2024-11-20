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
    vector<shared_ptr<Reservation>> sousReservations;  // Liste des sous-réservations

public:
    // Constructeur
    GroupeReservation(const string& date, const string& contact, const string& email);

    // Destructeur
    virtual ~GroupeReservation();

    // Méthodes pour manipuler les sous-réservations
    void ajouter(std::shared_ptr<Reservation> reservation);
    void supprimer(Reservation* reservation) override;
    Reservation* obtenirEnfant(int index) const override;

    // Méthodes spécifiques
    void afficherDetails() const override;  // Affiche les détails du groupe
    bool estGroupe() const override;       // Retourne true car c'est un groupe
};

#endif // GROUPERESERVATION_HPP
