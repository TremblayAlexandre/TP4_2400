// Visiteur.hpp
#ifndef VISITEUR_HPP
#define VISITEUR_HPP

class GroupeReservation;
class ReservationSimple;

class Visiteur {
public:
    virtual ~Visiteur() {}

    virtual void visiter(GroupeReservation& groupe) = 0;
    // Ajoutez d'autres m�thodes visiter pour d'autres types de r�servations si n�cessaire
};

#endif // VISITEUR_HPP
