///////////////////////////////////////////////////////////
//  Offre.h
//  Implementation of the Class Offre
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////
#ifndef OFFRE_HPP
#define OFFRE_HPP
#pragma once

#include <iostream>
#include "Devise.hpp"
#include "OffreAbstraite.hpp"
#include "ProxyOffreReservation.hpp"
#include "ObservateurRabais.hpp"
#include <unordered_map>

namespace std { class ProxyOffreReservation; }
using namespace std;

class Offre : public OffreAbstraite, public std::enable_shared_from_this<Offre> {
protected:
    std::shared_ptr<Devise> devise;
    std::string id;
    std::string nom;
    double prix;
    double prixOriginal;
    std::string type;
    std::string commentaire = "";
    unordered_map<string, shared_ptr<ObservateurRabais>> rabais;
    
public:
    Offre(std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, double prix, const std::string& type);
    ~Offre(); 
    string obtenirNom()const override {return nom;};
    string obtenirType()const override {return type;};
    string obtenirCommentaire()const  { return commentaire;};
    void definirCommentaire(const std::string& commentaire) { this->commentaire = commentaire; };
    virtual string obtenirDetails() const = 0;
    shared_ptr<Devise> obtenirDevise()const override {return devise;};
    double obtenirPrix()const override { return prix; };
    void definirPrix(double nouvPrix) { this->prix = nouvPrix; }
    double calculerPrixTotal(const string& autredevise, double taxe) const override;
    void ajouterObsRabais(const string& nom, shared_ptr<ObservateurRabais> obsRabais);
    void retirerObsRabais(const string& nom);
    
    shared_ptr<ProxyOffreReservation> reserver();
    friend class BDOReservation;
};



#endif // OFFRE_HPP
