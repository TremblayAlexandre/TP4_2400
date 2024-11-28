///////////////////////////////////////////////////////////
//  OffreVol.cpp
//  Implementation of the Class OffreVol
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "OffreVol.hpp"

OffreVol::OffreVol(std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, double prix, const std::string& date, const std::string& origine ="",
    const std::string& destination="")
    : Offre(devise, id, nom, prix, "Transport"), date(date), origine(origine), destination(destination) {}


void OffreVol::reserver(const std::string& client) {
}

