///////////////////////////////////////////////////////////
//  OffreVol.cpp
//  Implementation of the Class OffreVol
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "OffreVol.hpp"
#include <iostream>

namespace std {

    OffreVol::OffreVol(std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, const std::string& date, double prix, const std::string& origine ="", 
        const std::string& destination="", const std::string& heureDepart="")
        : Offre(devise, id, nom, date, prix, "Transport"), origine(origine), destination(destination), heureDepart(heureDepart){}


    void OffreVol::reserver(const std::string& client) {
    }

} // namespace std
