///////////////////////////////////////////////////////////
//  OffreExcursion.cpp
//  Implementation of the Class OffreExcursion
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////
#include <iostream>

#include "OffreExcursion.hpp"


OffreExcursion::OffreExcursion(std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, const std::string& date, double prix, const string& ville, int nbEtoiles)
    : Offre(devise, id, nom, date, prix, "Excursion"), ville(ville), nbEtoiles(nbEtoiles) {
        
}

void OffreExcursion::reserver(const std::string& client) {
}

