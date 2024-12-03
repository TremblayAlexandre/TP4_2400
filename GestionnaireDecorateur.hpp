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

    // Ajouter un décorateur de type `DecorateurAjoutReservation`
    shared_ptr<ReservationElement> ajouterDecorateur(shared_ptr<ReservationElement> objet,
        const string& nomReservation, const string& date, const string& heure, double coutsSupplementaire=0.0) {
        return make_shared<DecorateurAjoutReservation>(objet, nomReservation, date, heure, coutsSupplementaire);
    }

    // Ajouter un décorateur de type `DecorateurAjoutCommentaire`
    shared_ptr<ReservationElement> ajouterDecorateur(shared_ptr<ReservationElement> objet,
        const string& commentaire) {
        return make_shared<DecorateurAjoutCommentaire>(objet, commentaire);
    }

    // Enlever un décorateur spécifique (par propriété)
    shared_ptr<ReservationElement> enleverDecorateur(
        shared_ptr<ReservationElement> objet,
        const string& critere
    ) {
        if (!objet) return nullptr;

        // Pointeur pour reconstruire la chaîne sans le décorateur à enlever
        shared_ptr<ReservationElement> nouveauObjet = nullptr;
        shared_ptr<ReservationElement> objetActuel = objet;
        shared_ptr<ReservationElement> currentNewObj = objet;


        // Utilisons une pile pour stocker les décorateurs rencontrés
        vector<shared_ptr<ReservationElement>> pileDecorateurs;

        // Parcourir la chaîne de décorateurs
        while (objetActuel) {
            // Vérifier si l'objet actuel est un décorateur
            auto decorateurAbstrait = dynamic_pointer_cast<DecorateurAbstrait>(objetActuel);
            if (!decorateurAbstrait) {
                // C'est l'objet de base sans décorateur
                currentNewObj = objetActuel;
                break;
            }

            // Empiler le décorateur
            pileDecorateurs.push_back(decorateurAbstrait);
            // Passer au décorateur suivant dans la chaîne
            objetActuel = decorateurAbstrait->obtenirBase();
        }
        // Reconstruire la chaîne en excluant le décorateur correspondant
        for (auto it = pileDecorateurs.rbegin(); it != pileDecorateurs.rend(); ++it) {
            bool supprimer = false;

            // Vérifier le type de décorateur et comparer le critère
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
                // Ne pas inclure ce décorateur dans la nouvelle chaîne
                continue;
            }

            // Ajouter le décorateur à la nouvelle chaîne
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
            // Ajouter d'autres types de décorateurs si nécessaire
            currentNewObj = nouveauObjet;
        }

        // Si aucun décorateur n'a été supprimé, retourner l'objet original
        return nouveauObjet ? nouveauObjet : objetActuel;
    }
};

#endif // GESTIONNAIRE_DECORATEUR_HPP
