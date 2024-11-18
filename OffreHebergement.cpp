///////////////////////////////////////////////////////////
//  OffreHebergement.cpp
//  Implementation of the Class OffreHebergement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "OffreHebergement.hpp"
#include <iostream>

namespace std {

    OffreHebergement::OffreHebergement(const std::string& details, std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, double prix)
        : Offre(details, devise, id, nom, prix) {
    }

    void OffreHebergement::afficherDisponibilite() const {
    }

    double OffreHebergement::calculerPrixTotal(double taxe, const Devise& autreDevise) const {
        return 0.0;
    }

    vector<string> OffreHebergement::obtenirDisponibilite() const {
        return;
    }

    void OffreHebergement::reserver(const std::string& client) {
    }
    void OffreHebergement::definirAddresse(const string& addresse) {
        this->addresse = addresse;
    }

    string OffreHebergement::obtenirAddresse() const {
        return this->addresse;
    }

} // namespace std
