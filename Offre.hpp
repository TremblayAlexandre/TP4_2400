///////////////////////////////////////////////////////////
//  Offre.h
//  Implementation of the Class Offre
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////
#ifndef OFFRE_HPP
#define OFFRE_HPP

#include <iostream>
#include <string>
#include <memory> // Pour std::shared_ptr
#include "Devise.hpp"
#include "ProxyOffreReservation.hpp"
namespace std { class ProxyOffreReservation; }
using namespace std;

class Offre : public std::enable_shared_from_this<Offre> {
private:
    std::shared_ptr<Devise> devise;
    std::string id;
    std::string nom;
    double prix;
    std::string type;

public:
    Offre(std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, double prix, const std::string& type);
    ~Offre();   
    string obtenirNom()const{return nom;};
    string obtenirType()const{return type;};
    shared_ptr<Devise> obtenirDevise()const{return devise;};
    double obtenirPrix()const{return prix;};
    virtual double calculerPrixTotal(const Devise& autreDevise, double taxe = 1.0) const;
    shared_ptr<ProxyOffreReservation> reserver();
    friend class BDOReservation;
};



#endif // OFFRE_HPP
