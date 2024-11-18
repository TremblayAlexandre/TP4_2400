///////////////////////////////////////////////////////////
//  OffreVol.h
//  Implementation of the Class OffreVol
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef OFFRE_VOL_HPP
#define OFFRE_VOL_HPP

#include "Offre.hpp"
#include <string>

namespace std {

    class OffreVol : public Offre {
    private:
        std::string origine;
        std::string destination;
        std::string heureDepart;
        std::string heureArrivee;

    public:
        OffreVol(const std::string& details, std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, double prix);

        void afficherHoraire() const;
        void definirOrigine(const std::string& origine);
        void definirDestination(const std::string& destination);
        void definirHeureDepart(const std::string& heure);
        void definirHeureArrivee(const std::string& heure);

        bool verifierDisponibilitePlaces() const;
        void reserver(const std::string& client) override;
    };

} // namespace std

#endif // OFFRE_VOL_HPP
