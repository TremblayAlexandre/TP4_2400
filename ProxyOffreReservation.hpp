///////////////////////////////////////////////////////////
//  ProxyOffreReservation.h
//  Implementation of the Class ProxyOffreReservation
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef PROXY_OFFRE_RESERVATION_HPP
#define PROXY_OFFRE_RESERVATION_HPP

#include <memory> // Pour std::shared_ptr
#include <string>
#include "Offre.hpp"

namespace std {

    class ProxyOffreReservation {
    private:
        std::shared_ptr<Offre> offre;

    public:
        ProxyOffreReservation(std::shared_ptr<Offre> offre);
        void afficherNom() const;
        double calculerPrixTotal(double taxe, const Devise& autreDevise) const;
        string obtenirNom() const;
        

    };

} // namespace std

#endif // PROXY_OFFRE_RESERVATION_HPP
