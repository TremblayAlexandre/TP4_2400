///////////////////////////////////////////////////////////
//  Offre.h
//  Implementation of the Class Offre
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef OFFRE_HPP
#define OFFRE_HPP

#include <string>
#include <memory> // Pour std::shared_ptr
#include "Devise.hpp"

namespace std {

    class Offre {
    private:
        std::string details;
        std::shared_ptr<Devise> devise;
        std::string id;
        std::string nom;
        double prix;

    public:
        Offre(const std::string& details, std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, double prix);
        virtual void afficherDetails() const = 0;
        virtual double calculerPrixTotal(double taxe, const Devise& autreDevise) const = 0;
        virtual void reserver(const std::string& client) = 0;
        virtual string obtenirDetails() { return details; };
        virtual void definirDetail(string details) { this->details = details; }
    };

} // namespace std

#endif // OFFRE_HPP
