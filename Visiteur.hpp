// Visiteur.hpp
#ifndef VISITEUR_HPP
#define VISITEUR_HPP

class GroupeReservation;
class ReservationSimple;

class Visiteur {
public:
    virtual ~Visiteur() {}

    virtual void visiter(GroupeReservation& groupe) = 0;
    // Ajoutez d'autres méthodes visiter pour d'autres types de réservations si nécessaire
};

#endif // VISITEUR_HPP
