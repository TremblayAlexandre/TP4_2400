///////////////////////////////////////////////////////////
//  OffreVol.h
//  Implementation of the Class OffreVol
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef OFFRE_VOL_HPP
#define OFFRE_VOL_HPP
#pragma once

#include "Offre.hpp"


class OffreVol : public Offre {
private:
    std::string date;
    std::string origine;
    std::string destination;

public:
    OffreVol(std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, double prix, const std::string& date, const std::string& origine,
    const std::string& destination);
    
    void definirOrigine(const std::string& origine){this->origine = origine;};
    void definirDestination(const std::string& destination){this->destination = destination;};
    string obtenirOrigine(){return origine;};
    string obtenirDestination(){return destination;};
    string obtenirDate() {return date;};
    string obtenirDetails() const override;
};


#endif // OFFRE_VOL_HPP
