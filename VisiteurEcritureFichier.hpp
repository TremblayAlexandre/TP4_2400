#ifndef ECRITUREFICHIERVISITEUR_HPP
#define ECRITUREFICHIERVISITEUR_HPP

#include "Visiteur.hpp"
#include "GroupeReservation.hpp"
#include <fstream>
#include <string>
#include <stdexcept>

class EcritureFichierVisiteur : public Visiteur {
public:
    // Constructeur par d�faut
    EcritureFichierVisiteur() = default;

    // Destructeur par d�faut
    virtual ~EcritureFichierVisiteur() = default;

    // Override de la m�thode visiter
    virtual void visiter(GroupeReservation& groupe) override {
        // Obtenir le nom du titulaire pour d�terminer le nom du fichier
        std::string nomTitulaire = groupe.obtenirNomTitulaire();
        if (nomTitulaire.empty()) {
            throw std::runtime_error("Le nom du titulaire est vide.");
        }

        // D�finir le nom du fichier (par exemple, ajouter une extension .txt)
        std::string nomFichier = "log" + nomTitulaire + ".txt";

        // Ouvrir le fichier en mode append (ajout) ou cr�er s'il n'existe pas
        std::ofstream fichier(nomFichier, std::ios::out | std::ios::trunc);

        if (!fichier) {
            throw std::runtime_error("Impossible d'ouvrir ou de cr�er le fichier : " + nomFichier);
        }

        // �crire les d�tails dans le fichier
        fichier << groupe.obtenirDetails() << std::endl;

        // Le fichier est automatiquement ferm� � la fin du scope gr�ce au destructeur de std::ofstream
    }
};

#endif // ECRITUREFICHIERVISITEUR_HPP
