///////////////////////////////////////////////////////////
//  OffreHebergement.h
//  Implementation of the Class OffreHebergement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef OFFRE_HEBERGEMENT_HPP
#define OFFRE_HEBERGEMENT_HPP

#include "Offre.hpp"
#include <vector>

class OffreHebergement : public Offre {
private:
    string ville;
    double cote;
public:
    OffreHebergement(shared_ptr<Devise> devise, const std::string& id, const string& nom, double prix, const string& ville, double cote);
    
    void reserver(const string& client) override;
    string obtenirAddresse() const {return ville;};
    double obtenircote() const {return cote;};
    void definirCote(const int cote){this->cote = cote;};
};


#endif // OFFRE_HEBERGEMENT_HPP
