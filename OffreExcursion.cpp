///////////////////////////////////////////////////////////
//  OffreExcursion.cpp
//  Implementation of the Class OffreExcursion
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////
#include <iostream>

#include "OffreExcursion.hpp"

namespace std {

    OffreExcursion::OffreExcursion(const std::string& details, std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, double prix)
        : Offre(details, devise, id, nom, prix) {
    }

    void OffreExcursion::definirDescription(const std::string& description) {
        this->description = description;
    }

    void OffreExcursion::definirLieu(const std::string& lieu) {
        this->lieu = lieu;
    }

    std::string OffreExcursion::obtenirLieu() const {
        return lieu;
    }

    std::string OffreExcursion::obtenirDescription() const {
        return description;
    }

    void OffreExcursion::reserver(const std::string& client) {
    }

} // namespace std
