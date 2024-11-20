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
protected:
    string dateReservation;  
    string contactVendeur;   
    string emailVendeur;  

public:
    Reservation(const string& date, const string& contact, const string& email);

    virtual ~Reservation();

    string getDateReservation() const;
    string getContactVendeur() const;
    string getEmailVendeur() const;

    virtual void afficherDetails() const = 0;   
    virtual void ajouter(std::shared_ptr<Reservation> reservation);
    virtual void supprimer(Reservation* reservation); 
    virtual Reservation* obtenirEnfant(int index) const; 

    virtual bool estGroupe() const = 0;
};

#endif // RESERVATION_HPP
