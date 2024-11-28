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
using namespace std;

class Offre {
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
    virtual double calculerPrixTotal(double taxe, const Devise& autreDevise) const;
    virtual void reserver(const std::string& client) = 0;
    friend struct OffreComparator;
};

//struct OffreComparator {
//    bool operator()(const std::shared_ptr<Offre>& a, const std::shared_ptr<Offre>& b) const {
//        if (a->type != b->type) {
//            return a->type < b->type;
//        }
//        return a->id < b->id;
//    }
//};


#endif // OFFRE_HPP
