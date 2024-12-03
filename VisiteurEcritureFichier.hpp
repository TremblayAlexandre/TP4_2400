#ifndef ECRITUREFICHIERVISITEUR_HPP
#define ECRITUREFICHIERVISITEUR_HPP

#include "Visiteur.hpp"
#include "GroupeReservation.hpp"
#include <fstream>
#include <string>
#include <stdexcept>

class EcritureFichierVisiteur : public Visiteur {
public:
    // Constructeur par défaut
    EcritureFichierVisiteur() = default;

    // Destructeur par défaut
    virtual ~EcritureFichierVisiteur() = default;

    // Override de la méthode visiter
    virtual void visiter(GroupeReservation& groupe) override {
        // Obtenir le nom du titulaire pour déterminer le nom du fichier
        std::string nomTitulaire = groupe.obtenirNomTitulaire();
        if (nomTitulaire.empty()) {
            throw std::runtime_error("Le nom du titulaire est vide.");
        }

        // Définir le nom du fichier (par exemple, ajouter une extension .txt)
        std::string nomFichier = "log" + nomTitulaire + ".txt";

        // Ouvrir le fichier en mode append (ajout) ou créer s'il n'existe pas
        std::ofstream fichier(nomFichier, std::ios::out | std::ios::trunc);

        if (!fichier) {
            throw std::runtime_error("Impossible d'ouvrir ou de créer le fichier : " + nomFichier);
        }

        // Écrire les détails dans le fichier
        fichier << groupe.obtenirDetails() << std::endl;

        // Le fichier est automatiquement fermé à la fin du scope grâce au destructeur de std::ofstream
    }
};

#endif // ECRITUREFICHIERVISITEUR_HPP
