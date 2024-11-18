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
    public:
        OffreHebergement(const string& details, shared_ptr<Devise> devise, const string& id, const string& nom, double prix);
        void afficherDisponibilite() const;
        double calculerPrixTotal(double taxe, const Devise& autreDevise) const override;
        vector<string> obtenirDisponibilite() const;
        void reserver(const string& client) override;
        string obtenirAddresse() const;
        void definirAddresse(const string& addresse);
    };

} // namespace std

#endif // OFFRE_HEBERGEMENT_HPP
