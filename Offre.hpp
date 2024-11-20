///////////////////////////////////////////////////////////
//  Offre.h
//  Implementation of the Class Offre
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////
#pragma once
#ifndef OFFRE_HPP
#define OFFRE_HPP

#include <iostream>
#include <string>
#include <memory> // Pour std::shared_ptr
#include "Devise.hpp"
using namespace std;

class Offre {
private:
    std::shared_ptr<Devise> devise;
    std::string id;
    std::string nom;
    std::string date;
    double prix;
    std::string type;

public:
    Offre(std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, const std::string& date, double prix, const std::string& type);
    
    virtual void afficherDate()const{cout<<date<<endl;};
    string obtenirDate()const{return date;};    
    string obtenirNom()const{return nom;};
    string obtenirType()const{return type;};
    shared_ptr<Devise> obtenirDevise()const{return devise;};
    double obtenirPrix()const{return prix;};
    virtual double calculerPrixTotal(double taxe, const Devise& autreDevise) const;
    virtual void reserver(const std::string& client) = 0;
};


#endif // OFFRE_HPP
