///////////////////////////////////////////////////////////
//  OffreHebergement.h
//  Implementation of the Class OffreHebergement
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef OFFRE_HEBERGEMENT_HPP
#define OFFRE_HEBERGEMENT_HPP

#include "Offre.hpp"
#include <string>
#include <vector>

namespace std {

    class OffreHebergement : public Offre {
    private:
        string addresse;
        double cote;
    public:
        OffreHebergement(shared_ptr<Devise> devise, const std::string& id, const string& nom, const string& date, double prix, const string& addresse, double cote);
        void reserver(const string& client) override;
        string obtenirAddresse() const {return addresse;};
        int obtenircote() const {return cote;};
        void definirCote(const int cote){this->cote = cote;};
    };

} // namespace std

#endif // OFFRE_HEBERGEMENT_HPP
