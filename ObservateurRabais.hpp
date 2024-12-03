///////////////////////////////////////////////////////////
//  ObservateurRabais .h
//  Implementation of the Class ObservateurRabais 
//  Created on:      2-Dec-2024 2:28:21 PM
//  Original author: Massil
///////////////////////////////////////////////////////////

#ifndef OBSERVATEUR_RABAIS_HPP
#define OBSERVATEUR_RABAIS_HPP
#pragma once

#include <chrono>
using namespace std;

class ObservateurRabais {
private:
	double rabais;
	chrono::time_point<chrono::system_clock> dateFin;
public:
	ObservateurRabais(double rabais, double prixActuel, chrono::time_point<chrono::system_clock> dateFin);
	bool estRabaisActif()const { return dateFin > chrono::system_clock::now(); };
	double obtenirRabais() const{ return rabais; }
	virtual ~ObservateurRabais() {};
};


#endif