///////////////////////////////////////////////////////////
//  Reservation.h
//  Implementation of the Class Reservation
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#ifndef ITERATEUR_HPP
#define ITERATEUR_HPP

#include <vector>

template <typename T>
class Iterateur {
private:
    std::vector<T> liste;
    int position;

public:
    Iterateur(const std::vector<T>& liste) : liste(liste), position(0) {}

    bool hasNext() {
        return position < liste.size();
    }

    T next() {
        if (hasNext()) {
            return liste[position++];
        }
        throw std::out_of_range("No more elements");
    }

    void reset() {
        position = 0;
    }
};

#endif // ITERATEUR_HPP
