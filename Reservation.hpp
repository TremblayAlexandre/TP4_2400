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

class Reservation {
private:
    std::string dateDebut;
    std::string dateFin;
    std::vector<std::string> details;
    std::string nom;

public:
    void afficher() const;
    void ajouterDetails(const std::string& detail);
    void changerDates(std::string& debut, std::string& fin);
    void changerDetails(const std::vector<std::string>& nouveauxDetails);
    void changerNom(const std::string& nouveauNom);
    void supprimerDetail(const std::string& detail);
};

#endif // RESERVATION_HPP
