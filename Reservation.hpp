///////////////////////////////////////////////////////////
//  Reservation.h
//  Implementation of the Class Reservation
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <string>
#include <vector>
#include <memory>

using namespace std;
class Reservation {
private:
    string dateReservation;  
    string contactVendeur;   
    string emailVendeur;  
    string nomTitulaire;
    Reservation* parent = nullptr;
    bool aParent;

public:
    Reservation(const string& nom, const string& date, const string& contact, const string& email);
    Reservation(const Reservation& autre);


    virtual ~Reservation();

    string obtenirDateReservation() const;
    string obtenirContactVendeur() const;
    string obtenirEmailVendeur() const;
    string obtenirNomTitulaire() const;



    virtual vector<shared_ptr<Reservation>> obtenirEnfants() const = 0;
    virtual double obtenirCouts() const = 0;
    virtual void afficherDetails() const = 0;   
    virtual void ajouter(std::shared_ptr<Reservation> reservation) = 0;
    virtual void supprimer(Reservation* reservation) = 0;
    virtual Reservation* obtenirEnfant(int index) const = 0;

    bool obtenirAParent();
    void definirParent(Reservation*);
    Reservation* obtenirParent(Reservation* grpReservation);
    virtual bool estGroupe() const = 0;
};

#endif // RESERVATION_HPP
