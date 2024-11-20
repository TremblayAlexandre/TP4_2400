///////////////////////////////////////////////////////////
//  OffreHebergement.cpp
//  Implementation of the Class OffreHebergement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "OffreHebergement.hpp"
#include <iostream>


OffreHebergement::OffreHebergement(std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, const string& date, double prix, const string& ville, double cote):
Offre(devise, id, nom, date, prix, "Hebergement"), ville(ville), cote(cote) {
}

void OffreHebergement::reserver(const std::string& client) {
}



