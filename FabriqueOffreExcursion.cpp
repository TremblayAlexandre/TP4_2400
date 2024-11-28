///////////////////////////////////////////////////////////
//  FabriqueOffreExcursion.cpp
//  Implementation of the Class FabriqueOffreExcursion
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////
#include "FabriqueOffreExcursion.hpp"

    std::shared_ptr<OffreExcursion> FabriqueOffreExcursion::creerOffre(const std::string& id, const std::unordered_map<std::string, std::string>& params) {
        auto devise = std::make_shared<Devise>(params.at("devise"));
        auto offre = std::make_shared<OffreExcursion>(devise, id, params.at("nom"), stod(params.at("prix")), params.at("ville"), stoi(params.at("nbEtoiles")));
        return offre;
    }