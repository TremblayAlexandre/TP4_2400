///////////////////////////////////////////////////////////
//  FabriqueOffre.h
//  Implementation of the Class FabriqueOffre
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef FABRIQUE_OFFRE_HPP
#define FABRIQUE_OFFRE_HPP

#include "Offre.hpp"
#include <unordered_map>

class FabriqueOffre {
public:
    virtual std::shared_ptr<Offre> creerOffre(const string& id, const unordered_map<string, string>& params) = 0;
};

#endif // FABRIQUE_OFFRE_HPP
