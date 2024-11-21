///////////////////////////////////////////////////////////
//  OffreExcursion.h
//  Implementation of the Class OffreExcursion
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef OFFRE_EXCURSION_HPP
#define OFFRE_EXCURSION_HPP

#include "Offre.hpp"


class OffreExcursion : public Offre {
private:
    string ville;
    int nbEtoiles;

public:
    OffreExcursion(shared_ptr<Devise> devise, const std::string& id, const string& nom, double prix, const string& ville, int nbEtoiles);
    void definirNbEtoiles(const int nbEtoiles){this->nbEtoiles = nbEtoiles;};
    string obtenirVille() const{return ville;};
    int obtenirNbEtoiles() const{return nbEtoiles;};
    void reserver(const string& client) override;
};


#endif // OFFRE_EXCURSION_HPP
