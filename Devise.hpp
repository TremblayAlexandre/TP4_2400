///////////////////////////////////////////////////////////
//  Devise.h
//  Implementation of the Class Devise
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef DEVISE_HPP
#define DEVISE_HPP

#include <string>

namespace std {

    class Devise {
    private:
        std::string devise = "CAD";
        double tauxChange = 1.0;

    public:
        Devise(const std::string& devise, double tauxChange = 1.0);
        double convertir(double montant, const Devise& autreDevise) const;
    };

} // namespace std

#endif // DEVISE_HPP
