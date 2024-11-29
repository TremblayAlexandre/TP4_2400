///////////////////////////////////////////////////////////
//  BDORéservation .h
//  Implementation of the Class BDORéservation 
//  Created on:      17-Nov-2024 2:28:21 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef BDRESERVATION_HPP
#define BDRESERVATION_HPP

#include <vector>
#include "Offre.hpp"
#include <map>
#include <unordered_map>
using namespace std;

//template <typename T, typename Offre>
class BDOReservation{
private:
    unordered_map<string, unordered_map<string, shared_ptr<Offre>>> BD;

public:
    BDOReservation();
    void afficherOffres(const string& categorie="");
    void ajouterOffre(const shared_ptr<Offre>& offre);
    void ajouterCategorie(const string& categorie);
    shared_ptr<Offre> trouverOffreParNom(const string& nom);
    shared_ptr<Offre> trouverOffreParId(const string& id);
    std::vector<shared_ptr<Offre>> obtenirTousOffres() const;
    
};

#endif // BDRESERVATION_HPP

