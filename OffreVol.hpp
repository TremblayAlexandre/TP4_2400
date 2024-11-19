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
        OffreVol(std::shared_ptr<Devise> devise, const std::string& nom, const std::string& date, double prix, const std::string& origine, 
        const std::string& destination, const std::string& heureDepart, const std::string& heureArrivee);
        void definirOrigine(const std::string& origine){this->origine = origine;};
        void definirDestination(const std::string& destination){this->destination = destination;};
        void definirHeureDepart(const std::string& heure){this->heureDepart = heure;};
        void definirHeureArrivee(const std::string& heure){this->heureArrivee = heure;};
        string obtenirOrigine(){return origine;};
        string obtenirDestination(){return destination;};
        string obtenirHeureDepart(){return heureDepart;};
        string obtenirHeureArrivee(){return heureArrivee;};
        void reserver(const std::string& client) override;
    };

} // namespace std

#endif // OFFRE_VOL_HPP
