///////////////////////////////////////////////////////////
//  FabriqueHebergement.h
//  Implementation of the Class FabriqueHebergement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef FABRIQUE_OFFRE_HEBERGEMENT_HPP
#define FABRIQUE_OFFRE_HEBERGEMENT_HPP

#include "OffreHebergement.hpp"
#include <map>
#include <string>

namespace std {

    class FabriqueOffreHebergement {
    public:
        static std::shared_ptr<Offre> creerOffre(const std::string& id, const std::map<std::string, std::string>& params);
    };

} // namespace std

#endif // FABRIQUE_OFFRE_HEBERGEMENT_HPP
