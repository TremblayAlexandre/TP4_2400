///////////////////////////////////////////////////////////
//  FabriqueHebergement.cpp
//  Implementation of the Class FabriqueHebergement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "FabriqueOffreHebergement.hpp"
#include "OffreHebergement.hpp"

namespace std {

    std::shared_ptr<Offre> FabriqueOffreHebergement::creerOffre(const std::string& id, const std::map<std::string, std::string>& params) {
        auto devise = std::make_shared<Devise>(params.at("devise"));
        return std::make_shared<OffreHebergement>(params.at("details"), devise, id, params.at("nom"), std::stod(params.at("prix")));
    }

} // namespace std
