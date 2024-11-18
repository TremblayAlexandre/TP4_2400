///////////////////////////////////////////////////////////
//  Collections.h
//  Implementation of the Class Collections
//  Created on:      17-Nov-2024 2:28:21 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef COLLECTIONS_HPP
#define COLLECTIONS_HPP

#include <vector>
#include <functional>

template <typename T, typename Offre>
class Collections {
private:
    T categorie;
    std::vector<Offre> offres;

public:
    void ajouterOffre(const Offre& offre) {
        offres.push_back(offre);
    }

    void changerCategorie(const T& nouvelleCategorie) {
        categorie = nouvelleCategorie;
    }

    T obtenirCategorie() const {
        return categorie;
    }

    std::vector<Offre> obtenirOffres(std::function<bool(const Offre&)> filtre) const {
        std::vector<Offre> resultats;
        for (const auto& offre : offres) {
            if (filtre(offre)) {
                resultats.push_back(offre);
            }
        }
        return resultats;
    }

    std::vector<Offre> obtenirTousOffres() const {
        return offres;
    }
};

#endif // COLLECTIONS_HPP
