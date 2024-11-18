///////////////////////////////////////////////////////////
//  OffreVol.cpp
//  Implementation of the Class OffreVol
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "OffreVol.hpp"
#include <iostream>

namespace std {

    OffreVol::OffreVol(const std::string& details, std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, double prix)
        : Offre(details, devise, id, nom, prix), origine(""), destination(""), heureDepart(""), heureArrivee("") {}

    void OffreVol::afficherHoraire() const {
    }

    void OffreVol::definirOrigine(const std::string& origine) {
        this->origine = origine;
    }

    void OffreVol::definirDestination(const std::string& destination) {
        this->destination = destination;
    }

    void OffreVol::definirHeureDepart(const std::string& heure) {
        this->heureDepart = heure;
    }

    void OffreVol::definirHeureArrivee(const std::string& heure) {
        this->heureArrivee = heure;
    }

    bool OffreVol::verifierDisponibilitePlaces() const {
        return true; // todo
    }

    void OffreVol::reserver(const std::string& client) {
    }

} // namespace std
