///////////////////////////////////////////////////////////
//  FabriqueOffre.h
//  Implementation of the Class FabriqueOffre
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef FABRIQUE_OFFRE_HPP
#define FABRIQUE_OFFRE_HPP

#include "Offre.hpp"
#include <string>
#include <variant>
#include <unordered_map>
using namespace std;
using MultiType = variant<int, double, string>;

class FabriqueOffre {
public:
    virtual std::shared_ptr<Offre> creerOffre(const string& id, const unordered_map<std::string, MultiType>& params) = 0;
};

#endif // FABRIQUE_OFFRE_HPP
