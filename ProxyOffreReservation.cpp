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

    double ProxyOffreReservation::obtenirPrix() const {
        return offre->obtenirPrix();
    }

    double ProxyOffreReservation::calculerPrixTotal(const string& autreDevise, double taxe) const {
        return offre->calculerPrixTotal(autreDevise, taxe);
    }

    shared_ptr<Devise> ProxyOffreReservation::obtenirDevise()const {
        return offre->obtenirDevise();
    }
    string ProxyOffreReservation::obtenirType() const {
        return offre->obtenirType();
    }
    std::string ProxyOffreReservation::obtenirNom() const {
        return offre->obtenirNom();
    }

} // namespace std
