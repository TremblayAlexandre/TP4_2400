///////////////////////////////////////////////////////////
//  FabriqueHebergement.h
//  Implementation of the Class FabriqueHebergement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef FABRIQUE_OFFRE_HEBERGEMENT_HPP
#define FABRIQUE_OFFRE_HEBERGEMENT_HPP

#include "OffreHebergement.hpp"
#include "FabriqueOffre.hpp"
using namespace std;


class FabriqueOffreHebergement: public FabriqueOffre {
public:
    std::shared_ptr<Offre> creerOffre(const std::string& id, const std::unordered_map<std::string, std::string>& params) override;
};


#endif // FABRIQUE_OFFRE_HEBERGEMENT_HPP
