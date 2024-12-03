// AffichageVisiteur.hpp
#ifndef AFFICHAGEVISITEUR_HPP
#define AFFICHAGEVISITEUR_HPP

#include "Visiteur.hpp"
#include <iostream>
#include "GroupeReservation.hpp"



class AffichageVisiteur : public Visiteur {
public:
    virtual void visiter(GroupeReservation& groupe) override {
        std::cout << groupe.obtenirDetails() << std::endl;
    }

};

#endif // AFFICHAGEVISITEUR_HPP