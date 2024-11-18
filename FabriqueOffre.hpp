///////////////////////////////////////////////////////////
//  FabriqueOffre.h
//  Implementation of the Class FabriqueOffre
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef FABRIQUE_OFFRE_HPP
#define FABRIQUE_OFFRE_HPP

#include "Offre.hpp"
#include <map>
#include <string>

namespace std {

    class FabriqueOffre {
    public:
        virtual std::shared_ptr<Offre> creerOffre(const std::string& id, const std::map<std::string, std::string>& params) = 0;
    };

} // namespace std

#endif // FABRIQUE_OFFRE_HPP
