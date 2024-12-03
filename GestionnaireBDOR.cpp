///////////////////////////////////////////////////////////
//  GestionnaireBDOR .cpp
//  Implementation of the Class GestionnaireBDOr 
//  Created on:      2-Dec-2024 2:28:21 PM
//  Original author: Massil
///////////////////////////////////////////////////////////

#include "GestionnaireBDOR.hpp"

GestionnaireBDOR::GestionnaireBDOR(shared_ptr<BDOReservation> bdor): BDOR(bdor){}

void GestionnaireBDOR::attribuerCommentaire(const string& nomOffre, const string& commentaire){
	shared_ptr<Offre> offre = this->BDOR->trouverOffreParNom(nomOffre);
	if (offre) {
		offre->definirCommentaire(commentaire);
	}
}

void GestionnaireBDOR::retirerCommentaire(const string& nomOffre){
	shared_ptr<Offre> offre = this->BDOR->trouverOffreParNom(nomOffre);
	if (offre) {
		offre->definirCommentaire("");
	}
}

//void GestionnaireBDOR::appliquerRabais(double rabais, const string& nomOffre, duree){
//	shared_ptr<Offre> offre = this->BDOR->trouverOffreParNom(nomOffre);
//	if (offre) {
//		offre->definirPrix(offre->obtenirPrix() - rabais);
//	}
//}

void GestionnaireBDOR::ajusterPrixDeTypes(double facteur, const unordered_set<string> types) {
	for (string type: types) {
		if (BDOR->BD.contains(type)) {
			for (const auto& pair : BDOR->BD.at(type)) {
				shared_ptr<Offre> offre = pair.second;
				offre->definirPrix(offre->obtenirPrix() * facteur);
			}
		}
	}
}
void GestionnaireBDOR::ajusterPrixSaufTypes(double facteur, const unordered_set<string> types) {
	for (const auto& pair: BDOR->BD) {
		if (!types.contains(pair.first)) {
			for (const auto& pair : pair.second) {
				shared_ptr<Offre> offre = pair.second;
				offre->definirPrix(offre->obtenirPrix() * facteur);
			}
		}
	}
}

int GestionnaireBDOR::obtenirNbOffres() { return BDOR->obtenirNbOffres();}