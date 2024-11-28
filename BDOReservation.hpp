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
#include <map>;
#include <unordered_map>
using namespace std;

//template <typename T, typename Offre>
class BDOReservation{
private:
    unordered_map<string, map<string, shared_ptr<Offre>>> BD;
    friend class Offre;

public:
    BDOReservation() {};
    void afficherOffres();
    void ajouterOffre(const shared_ptr<Offre>& offre);
    //std::vector<Offre> obtenirOffres(std::function<bool(const Offre&)> filtre) const;
    std::vector<Offre> obtenirTousOffres() const;
    
};

#endif // BDRESERVATION_HPP

