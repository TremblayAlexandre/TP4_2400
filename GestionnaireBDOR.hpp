///////////////////////////////////////////////////////////
//  GestionnaireBDOR .h
//  Implementation of the Class GestionnaireBDOr 
//  Created on:      2-Dec-2024 2:28:21 PM
//  Original author: Massil
///////////////////////////////////////////////////////////

#ifndef GESTIONNAIREBDOR_HPP
#define GESTIONNAIREBDOR_HPP
#pragma once

#include "BDOReservation.hpp"
#include <unordered_set>

class GestionnaireBDOR {
private:
	shared_ptr<BDOReservation> BDOR;
public:
	GestionnaireBDOR(shared_ptr<BDOReservation> bdor);
	void attribuerCommentaire(const string& nomOffre, const string& commentaire);
	void retirerCommentaire(const string& nomOffre);
	void appliquerRabais(double rabais, const string& nomOffre, int nb);
	void ajusterPrixDeTypes(double facteur, const unordered_set<string> types );
	void ajusterPrixSaufTypes(double facteur, const unordered_set<string> types = {});
	int obtenirNbOffres();

};

#endif

