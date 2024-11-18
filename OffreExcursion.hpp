///////////////////////////////////////////////////////////
//  OffreExcursion.h
//  Implementation of the Class OffreExcursion
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef OFFRE_EXCURSION_HPP
#define OFFRE_EXCURSION_HPP

#include "Offre.hpp"
#include <string>

namespace std {

    class OffreExcursion : public Offre {
    private:
        string description;
        string lieu;

    public:
        OffreExcursion(const string& details, shared_ptr<Devise> devise, const string& id, const string& nom, double prix);

        void definirDescription(const string& description);
        void definirLieu(const string& lieu);

        string obtenirLieu() const;
        string obtenirDescription() const;
        void reserver(const string& client) override;
    };

} // namespace std

#endif // OFFRE_EXCURSION_HPP
