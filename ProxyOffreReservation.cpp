///////////////////////////////////////////////////////////
//  ProxyOffreReservation.cpp
//  Implementation of the Class ProxyOffreReservation
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "ProxyOffreReservation.hpp"
#include <iostream>

namespace std {

    ProxyOffreReservation::ProxyOffreReservation(std::shared_ptr<Offre> offre)
        : offre(offre) {
    }

    void ProxyOffreReservation::afficherNom() const {
        std::cout << "Détails de l'offre: " << obtenirNom() << std::endl;
    }

    double ProxyOffreReservation::calculerPrixTotal(double taxe, const Devise& autreDevise) const {
        return offre->calculerPrixTotal(autreDevise, taxe);  
    }

    std::string ProxyOffreReservation::obtenirNom() const {
        return offre->obtenirNom(); 
    }

} // namespace std
