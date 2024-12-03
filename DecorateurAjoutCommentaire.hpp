#ifndef DECORATEUR_AJOUT_COMMENTAIRE_HPP
#define DECORATEUR_AJOUT_COMMENTAIRE_HPP

#include "DecorateurAbstrait.hpp"

using namespace std;
class DecorateurAjoutCommentaire : public DecorateurAbstrait {
private:
    std::string commentaire;

public:
    DecorateurAjoutCommentaire(shared_ptr<ReservationElement> base, const std::string& commentaire) :
        DecorateurAbstrait(base), commentaire(commentaire) {};
    virtual ~DecorateurAjoutCommentaire() {};

    string obtenirCommentaire() { return commentaire; }
    std::string obtenirDetails() const override {
        string details = base->obtenirDetails(); 
        details += "         ";
        details +=  "Commentaire: " + commentaire + ".\n";
        return details;
    };
};

#endif // DECORATEUR_AJOUT_COMMENTAIRE_HPP
