///////////////////////////////////////////////////////////
//  Devise.cpp
//  Implementation of the Class Devise
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "Devise.hpp"

namespace std {

    Devise::Devise(const std::string& devise, double tauxChange)
        : devise(devise), tauxChange(tauxChange) {
        if (devise == "CDN") { this->devise = "CAD"; }
        if (devise == "EURO") { this->tauxChange = 1.5; }
        // Constructeur initialisé
    }

    double Devise::convertir(double montant, const Devise& autreDevise) const {
        // todo cest pas implémenté
        return (montant * tauxChange) / autreDevise.tauxChange;
    }
    void Devise::changerTauxChange(double nouveauTaux) {
        if (nouveauTaux > 0.0) { this->tauxChange = nouveauTaux; }
    }

} // namespace std
