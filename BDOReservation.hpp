///////////////////////////////////////////////////////////
//  BDORéservation .h
//  Implementation of the Class BDORéservation 
//  Created on:      17-Nov-2024 2:28:21 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef BDRESERVATION_HPP
#define BDRESERVATION_HPP

#include <vector>
#include "Collections.hpp"

template <typename T, typename Offre>
class BDOReservation{
private:
    std::vector<Collections<T, Offre>> collections;
    int iterateurCollection;

public:
    void afficherOffres();
    void ajouterCollection(const Collections<T, Offre>& collection);
    std::vector<Collections<T, Offre>> obtenirCollections() const;
    void ajouterOffre(const Offre& offre);
    std::vector<Offre> obtenirOffres(std::function<bool(const Offre&)> filtre) const;
    std::vector<Offre> obtenirTousOffres() const;
};

#endif // BDRESERVATION_HPP

