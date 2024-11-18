///////////////////////////////////////////////////////////
//  FabriqueOffreVol.cpp
//  Implementation of the Class FabriqueOffreVol
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "FabriqueOffreVol.hpp"
#include "OffreVol.hpp"

namespace std {

    std::shared_ptr<Offre> FabriqueOffreVol::creerOffre(const std::string& id, const std::map<std::string, std::string>& params) {
        auto devise = std::make_shared<Devise>(params.at("devise"));
        auto offre = std::make_shared<OffreVol>(params.at("details"), devise, id, params.at("nom"), std::stod(params.at("prix")));
        offre->definirOrigine(params.at("origine"));
        offre->definirDestination(params.at("destination"));
        offre->definirHeureDepart(params.at("heureDepart"));
        offre->definirHeureArrivee(params.at("heureArrivee"));
        return offre;
    }

} // namespace std
