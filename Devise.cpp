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
        // Constructeur initialisé
    }

    double Devise::convertir(double montant, const Devise& autreDevise) const {
        // todo cest pas implémenté
        if (tauxChange == 0 || autreDevise.tauxChange == 0) {
            return -1.0;
        }
        return (montant / tauxChange) * autreDevise.tauxChange;
    }

} // namespace std
