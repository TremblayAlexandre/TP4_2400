///////////////////////////////////////////////////////////
//  FabriqueOffreVol.h
//  Implementation of the Class FabriqueOffreVol
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef FABRIQUE_OFFRE_VOL_HPP
#define FABRIQUE_OFFRE_VOL_HPP

#include "OffreVol.hpp"
#include "FabriqueOffre.hpp"

namespace std {

    class FabriqueOffreVol: public FabriqueOffre {
    public:
        std::shared_ptr<Offre> creerOffre(const std::string& id, const std::unordered_map<std::string, std::string>& params) override;
    };

} // namespace std

#endif // FABRIQUE_OFFRE_VOL_HPP
