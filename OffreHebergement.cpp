///////////////////////////////////////////////////////////
//  OffreHebergement.cpp
//  Implementation of the Class OffreHebergement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "OffreHebergement.hpp"
#include <iostream>


OffreHebergement::OffreHebergement(std::shared_ptr<Devise> devise, const std::string& nom, const string& date, double prix, const string& addresse, double cote):
Offre(devise, nom, date, prix, "Hebergement"), addresse(addresse), cote(cote) {
}

void OffreHebergement::reserver(const std::string& client) {
}



