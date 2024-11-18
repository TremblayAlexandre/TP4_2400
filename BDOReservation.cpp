///////////////////////////////////////////////////////////
//  BDORéservation.cpp
//  Implementation of the Class BDORéservation 
//  Created on:      17-Nov-2024 2:28:21 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "BDOReservation.hpp"

template <typename T, typename Offre>
void BDOReservation<T, Offre>::afficherOffres() {
}

template <typename T, typename Offre>
void BDOReservation<T, Offre>::ajouterCollection(const Collections<T, Offre>& collection) {
}

template <typename T, typename Offre>
std::vector<Collections<T, Offre>> BDOReservation<T, Offre>::obtenirCollections() const {
    return {};
}

template <typename T, typename Offre>
void BDOReservation<T, Offre>::ajouterOffre(const Offre& offre) {
}

template <typename T, typename Offre>
std::vector<Offre> BDOReservation<T, Offre>::obtenirOffres(std::function<bool(const Offre&)> filtre) const {
    return {};
}

template <typename T, typename Offre>
std::vector<Offre> BDOReservation<T, Offre>::obtenirTousOffres() const {
    return {};
}


