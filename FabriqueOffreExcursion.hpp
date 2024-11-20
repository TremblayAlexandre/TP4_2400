///////////////////////////////////////////////////////////
//  FabriqueOffreExcursion.h
//  Implementation of the Class FabriqueOffreExcursion
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef FABRIQUE_OFFRE_EXCURSION_HPP
#define FABRIQUE_OFFRE_EXCURSION_HPP
#include "FabriqueOffre.hpp"
#include "OffreExcursion.hpp"
#include <string>
using namespace std;

class FabriqueOffreExcursion: public FabriqueOffre {
public:
    std::shared_ptr<Offre> creerOffre(const string& id, const unordered_map<std::string, std::string>& params) override;
};


#endif // FABRIQUE_OFFRE_EXCURSION_HPP
