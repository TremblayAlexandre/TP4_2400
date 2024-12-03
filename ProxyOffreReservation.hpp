///////////////////////////////////////////////////////////
//  ProxyOffreReservation.h
//  Implementation of the Class ProxyOffreReservation
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef PROXY_OFFRE_RESERVATION_HPP
#define PROXY_OFFRE_RESERVATION_HPP
#pragma once

#include "OffreAbstraite.hpp"
#include "Offre.hpp"

class Offre;
namespace std {

    class ProxyOffreReservation: public OffreAbstraite {
    private:
        std::shared_ptr<Offre> offre;

    public:
        ProxyOffreReservation(std::shared_ptr<Offre> offre);
        string obtenirNom() const override;
        string obtenirType()const override;
        shared_ptr<Devise> obtenirDevise()const override;
        double obtenirPrix()const override;
        double calculerPrixTotal(const string& autredevise, double taxe) const override;


    };

} // namespace std

#endif // PROXY_OFFRE_RESERVATION_HPP
