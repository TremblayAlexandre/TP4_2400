///////////////////////////////////////////////////////////
//  Offre.cpp
//  Implementation of the Class Offre
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "Offre.hpp"


Offre::Offre(std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, const std::string& date, double prix, const std::string& type):
	devise(devise), id(id), nom(nom), date(date), prix(prix), type(type)
	{cout << "Entree" << " " << nom << "rattachee a la categorie" << " " << type << " " << "cree!" << endl; }


Offre::~Offre(){
};


double Offre::calculerPrixTotal(double taxe, const Devise& autreDevise) const{
	double montant = prix * taxe;
	double montantTot = (*devise).convertir(montant, autreDevise);
	return montantTot;
}
