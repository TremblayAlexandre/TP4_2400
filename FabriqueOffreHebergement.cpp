///////////////////////////////////////////////////////////
//  FabriqueHebergement.cpp
//  Implementation of the Class FabriqueHebergement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "FabriqueOffreHebergement.hpp"

std::shared_ptr<OffreHebergement> FabriqueOffreHebergement::creerOffre(const std::string& id, const unordered_map<std::string, std::string>& params) {
    auto devise = std::make_shared<Devise>(params.at("devise"));
    auto offre = std::make_shared<OffreHebergement>(devise, id, params.at("nom"), stod(params.at("prix")), params.at("ville"), stod(params.at("cote")));
    return offre;
}


