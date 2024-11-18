///////////////////////////////////////////////////////////
//  FabriqueOffreExcursion.h
//  Implementation of the Class FabriqueOffreExcursion
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef FABRIQUE_OFFRE_EXCURSION_HPP
#define FABRIQUE_OFFRE_EXCURSION_HPP

#include "OffreExcursion.hpp"
#include <map>
#include <string>

namespace std {

    class FabriqueOffreExcursion {
    public:
        static std::shared_ptr<Offre> creerOffre(const std::string& id, const std::map<std::string, std::string>& params);
    };

} // namespace std

#endif // FABRIQUE_OFFRE_EXCURSION_HPP
