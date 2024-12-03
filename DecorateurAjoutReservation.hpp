#ifndef DECORATEUR_AJOUT_RESERVATION_HPP
#define DECORATEUR_AJOUT_RESERVATION_HPP

#include "DecorateurAbstrait.hpp"
using namespace std;

class DecorateurAjoutReservation : public DecorateurAbstrait {
private:
    string nomReservation;
    string date;
    string heure;
    double coutsSupplementaire;

public:
    DecorateurAjoutReservation(shared_ptr<ReservationElement> base, const string& nom, const string& date, const string& heure, double couts) :
        DecorateurAbstrait(base) , coutsSupplementaire(couts), nomReservation(nom), date(date), heure(heure)  {};
    virtual ~DecorateurAjoutReservation() {};
    string obtenirNomReservation() { return nomReservation; }
    double obtenirCouts(const string& autredevise="CAD", double taxe=1.0) const override {
        return base->obtenirCouts(autredevise,taxe) + coutsSupplementaire; };
    string obtenirDate() { return date; }
    string obtenirHeure() { return heure; }

    std::string obtenirDetails() const override { 
        string details = base->obtenirDetails();
        details += "         ";
        details += "Reservation " + nomReservation + ". \n";
        return details; };
};

#endif // DECORATEUR_AJOUT_RESERVATION_HPP
