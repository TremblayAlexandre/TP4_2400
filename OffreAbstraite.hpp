// OffreAbstraite.h
///////////////////////////////////////////////////////////
//  OffreAbstraite.h
//  Abstract class definition for Offre
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef OFFRE_ABSTRAITE_HPP
#define OFFRE_ABSTRAITE_HPP

#include <string>
#include <memory>
#include "Devise.hpp"

namespace std {
    class OffreAbstraite {
    public:
        OffreAbstraite() {}
        virtual ~OffreAbstraite() {}

        virtual string obtenirNom() const = 0;
        virtual string obtenirType() const = 0;
        virtual shared_ptr<Devise> obtenirDevise() const = 0;
        virtual double obtenirPrix() const = 0;
        virtual double calculerPrixTotal(const string& autredevise = "CAD", double taxe = 1.0) const = 0;
    };
}
#endif // OFFRE_ABSTRAITE_HPP
