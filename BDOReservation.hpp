///////////////////////////////////////////////////////////
//  BDORéservation .h
//  Implementation of the Class BDORéservation 
//  Created on:      17-Nov-2024 2:28:21 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef BDORESERVATION_HPP
#define BDORESERVATION_HPP
#pragma once

#include <vector>
#include "Offre.hpp"
#include "ObservateurRabais.hpp"

using namespace std;

//template <typename T, typename Offre>
class BDOReservation{
private:
    BDOReservation() = default;
    static BDOReservation* instance;
    unordered_map<string, unordered_map<string, shared_ptr<Offre>>> BD;
    static int nombreOffres;

public:
    BDOReservation(const BDOReservation&) = delete;
    BDOReservation& operator=(const BDOReservation&) = delete;
    static BDOReservation* getInstance();
    ~BDOReservation() = default;

    void afficherOffres(const string& categorie="");
    void ajouterOffre(const shared_ptr<Offre>& offre);
    void ajouterCategorie(const string& categorie);
    shared_ptr<Offre> trouverOffreParNom(const string& nom);
    shared_ptr<Offre> trouverOffreParId(const string& id);
    std::vector<shared_ptr<Offre>> obtenirTousOffres() const;
    int obtenirNbOffres() { return nombreOffres; }
    friend class GestionnaireBDOR;
    
};

#endif // BDORESERVATION_HPP

