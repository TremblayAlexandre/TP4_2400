#ifndef DECORATEUR_ABSTRAIT_HPP
#define DECORATEUR_ABSTRAIT_HPP

#include "ReservationElement.hpp"
#include <memory>
using namespace std;
class DecorateurAbstrait : public ReservationElement {
protected:
    shared_ptr<ReservationElement> base;

public:
    DecorateurAbstrait(shared_ptr<ReservationElement> base) : ReservationElement(*base) , base(base) {};
    virtual ~DecorateurAbstrait() {};
    shared_ptr<ReservationElement> obtenirBase() const { return base; };
    virtual double obtenirCouts(const string& autredevise, double taxe) const override { return base->obtenirCouts(autredevise, taxe); };
    virtual std::string obtenirDetails() const override = 0;
};

#endif // DECORATEUR_ABSTRAIT_HPP
