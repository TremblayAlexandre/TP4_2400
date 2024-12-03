///////////////////////////////////////////////////////////
//  FabriqueOffreExcursion.h
//  Implementation of the Class FabriqueOffreExcursion
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef FABRIQUE_OFFRE_EXCURSION_HPP
#define FABRIQUE_OFFRE_EXCURSION_HPP
#pragma once

#include "OffreExcursion.hpp"

class FabriqueOffreExcursion {
public:
    std::shared_ptr<OffreExcursion> creerOffre(const string& id, const unordered_map<std::string, std::string>& params);
};


#endif // FABRIQUE_OFFRE_EXCURSION_HPP
