///////////////////////////////////////////////////////////
//  FabriqueOffreVol.cpp
//  Implementation of the Class FabriqueOffreVol
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "FabriqueOffreVol.hpp"
#include "OffreVol.hpp"

namespace std {

    std::shared_ptr<Offre> FabriqueOffreVol::creerOffre(const std::string& id, const unordered_map<std::string, std::string>& params) {
        auto devise = std::make_shared<Devise>(params.at("devise"));
        auto offre = std::make_shared<OffreVol>(devise, id, params.at("nom"), params.at("date"), stod(params.at("prix")), params.at("origine"), params.at("destination"), params.at("heureDepart"));
        return offre;
    }

} // namespace std
