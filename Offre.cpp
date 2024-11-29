///////////////////////////////////////////////////////////
//  Offre.cpp
//  Implementation of the Class Offre
//  Created on:      17-Nov-2024 2:28:22 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "Offre.hpp"


Offre::Offre(std::shared_ptr<Devise> devise, const std::string& id, const std::string& nom, double prix, const std::string& type):
	devise(devise), id(id), nom(nom), prix(prix), type(type)
	{cout << "Entree" << " " << nom << " rattachee a la categorie" << " " << type << " " << "cree!" << endl; }


Offre::~Offre(){
};


double Offre::calculerPrixTotal(const string& autredevise, double taxe) const{
	Devise autreDev = Devise(autredevise);
	double montant = prix * taxe;
	double montantTot = devise->convertir(montant, autreDev);
	return montantTot;
}

shared_ptr<ProxyOffreReservation> Offre::reserver() {
	return make_shared<ProxyOffreReservation>(shared_from_this());
}
