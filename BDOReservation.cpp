///////////////////////////////////////////////////////////
//  BDORéservation.cpp
//  Implementation of the Class BDORéservation 
//  Created on:      17-Nov-2024 2:28:21 PM
//  Original author: Alex
///////////////////////////////////////////////////////////

#include "BDOReservation.hpp"

BDOReservation* BDOReservation::instance = nullptr;
int BDOReservation::nombreOffres = 0;


BDOReservation* BDOReservation::obtenirInstance() {
	if (instance == nullptr) {
		instance = new BDOReservation();
		cout << "Objet BDOR cree!" << endl;
		instance->ajouterCategorie("Transport");
		instance->ajouterCategorie("Hebergement");
		instance->ajouterCategorie("Excursion");
	}
	return instance;

}

void BDOReservation::afficherOffres(const string& categorie){
	if (categorie == "") {
		for (const auto& pair : this->BD) {
			for (const auto& pair : pair.second) {
				cout << pair.second->obtenirNom() << " : " << pair.second->obtenirPrix() << endl;
			}
		}
	}
	else {
		if (this->BD.contains(categorie)) {
			for (const auto& pair : this->BD.at(categorie)) {
				cout << pair.second->obtenirNom() << " : " << pair.second->obtenirPrix() << endl;
			}
		}
	}
}

void BDOReservation::ajouterOffre(const shared_ptr<Offre>& offre){
	if (!this->BD.contains(offre->obtenirType())) {
		ajouterCategorie(offre->obtenirType());
	}
	this->BD.at(offre->obtenirType())[offre->id] = offre;
	nombreOffres += 1;
}

void BDOReservation::ajouterCategorie(const string& categorie){
	if (!this->BD.contains(categorie)) {
		this->BD[categorie];
		cout << "Categorie " << categorie << " creee!" << endl;
	}
}

shared_ptr<Offre> BDOReservation::trouverOffreParNom(const string& nom) {
	for (const auto& pair : this->BD) {
		for (const auto& pair : pair.second) {
			if (pair.second->obtenirNom().find(nom) != string::npos) {
				return pair.second;
			}
		}
	}
	return nullptr;
}

shared_ptr<Offre> BDOReservation::trouverOffreParId(const string& id) {
	for (const auto& pair : this->BD) {
		if (pair.second.contains(id)) {
			return pair.second.at(id);
		}
	}
	return nullptr;
}

std::vector<shared_ptr<Offre>> BDOReservation::obtenirTousOffres() const{
	vector<shared_ptr<Offre>> offres;

	for (const auto& pair : this->BD) {
		for (const auto& pair : pair.second) {
			offres.push_back(pair.second);
		}

	}
	return offres;
}




