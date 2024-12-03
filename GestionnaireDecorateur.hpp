#ifndef GESTIONNAIRE_DECORATEUR_HPP
#define GESTIONNAIRE_DECORATEUR_HPP

#include "DecorateurAjoutReservation.hpp"
#include "DecorateurAjoutCommentaire.hpp"
#include <memory>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class GestionnaireDecorateur {
public:
    GestionnaireDecorateur() = default;

    // Ajouter un d�corateur de type `DecorateurAjoutReservation`
    shared_ptr<ReservationElement> ajouterDecorateur(shared_ptr<ReservationElement> objet,
        const string& nomReservation, const string& date, const string& heure, double coutsSupplementaire=0.0) {
        return make_shared<DecorateurAjoutReservation>(objet, nomReservation, date, heure, coutsSupplementaire);
    }

    // Ajouter un d�corateur de type `DecorateurAjoutCommentaire`
    shared_ptr<ReservationElement> ajouterDecorateur(shared_ptr<ReservationElement> objet,
        const string& commentaire) {
        return make_shared<DecorateurAjoutCommentaire>(objet, commentaire);
    }

    // Enlever un d�corateur sp�cifique (par propri�t�)
    shared_ptr<ReservationElement> enleverDecorateur(
        shared_ptr<ReservationElement> objet,
        const string& critere
    ) {
        if (!objet) return nullptr;

        // Pointeur pour reconstruire la cha�ne sans le d�corateur � enlever
        shared_ptr<ReservationElement> nouveauObjet = nullptr;
        shared_ptr<ReservationElement> objetActuel = objet;
        shared_ptr<ReservationElement> currentNewObj = objet;


        // Utilisons une pile pour stocker les d�corateurs rencontr�s
        vector<shared_ptr<ReservationElement>> pileDecorateurs;

        // Parcourir la cha�ne de d�corateurs
        while (objetActuel) {
            // V�rifier si l'objet actuel est un d�corateur
            auto decorateurAbstrait = dynamic_pointer_cast<DecorateurAbstrait>(objetActuel);
            if (!decorateurAbstrait) {
                // C'est l'objet de base sans d�corateur
                currentNewObj = objetActuel;
                break;
            }

            // Empiler le d�corateur
            pileDecorateurs.push_back(decorateurAbstrait);
            // Passer au d�corateur suivant dans la cha�ne
            objetActuel = decorateurAbstrait->obtenirBase();
        }
        // Reconstruire la cha�ne en excluant le d�corateur correspondant
        for (auto it = pileDecorateurs.rbegin(); it != pileDecorateurs.rend(); ++it) {
            bool supprimer = false;

            // V�rifier le type de d�corateur et comparer le crit�re
            if (auto decorateurCommentaire = dynamic_pointer_cast<DecorateurAjoutCommentaire>(*it)) {
                if (decorateurCommentaire->obtenirCommentaire() == critere) {
                    supprimer = true;
                }
            }
            else if (auto decorateurReservation = dynamic_pointer_cast<DecorateurAjoutReservation>(*it)) {
                if (decorateurReservation->obtenirNomReservation() == critere) {
                    supprimer = true;
                }
            }

            if (supprimer) {
                // Ne pas inclure ce d�corateur dans la nouvelle cha�ne
                continue;
            }

            // Ajouter le d�corateur � la nouvelle cha�ne
            if (auto decorateurCommentaire = dynamic_pointer_cast<DecorateurAjoutCommentaire>(*it)) {
                nouveauObjet = make_shared<DecorateurAjoutCommentaire>(
                    currentNewObj,
                    decorateurCommentaire->obtenirCommentaire()
                    );
            }
            else if (auto decorateurReservation = dynamic_pointer_cast<DecorateurAjoutReservation>(*it)) {
                nouveauObjet = make_shared<DecorateurAjoutReservation>(
                    currentNewObj,
                    decorateurReservation->obtenirNomReservation(),
                    decorateurReservation->obtenirDate(),
                    decorateurReservation->obtenirHeure(),
                    decorateurReservation->obtenirCouts()
                    );
            }
            // Ajouter d'autres types de d�corateurs si n�cessaire
            currentNewObj = nouveauObjet;
        }

        // Si aucun d�corateur n'a �t� supprim�, retourner l'objet original
        return nouveauObjet ? nouveauObjet : objetActuel;
    }
};

#endif // GESTIONNAIRE_DECORATEUR_HPP
