#include "pion.h"

pion::pion(const couleur &C, const position &P) : piece(C, P),premierCoup(true){}


unsigned short pion::valeur() const
{
    return 1;
}

void pion::deplacementPossibles()
{
    viderDeplacement();
    if(getColor() == couleur::BLANC){
        if(position(P().horizontal(),P().vertical()+1).estValide()) ajouterDeplacement(position(P().horizontal(),P().vertical()+1));
        if(premierCoup) ajouterDeplacement(position(P().horizontal(),P().vertical()+2));
    }
    if(getColor() == couleur::NOIR){
        if(position(P().horizontal(),P().vertical()-1).estValide()) ajouterDeplacement(position(P().horizontal(),P().vertical()-1));
        if(premierCoup) ajouterDeplacement(position(P().horizontal(),P().vertical()-2));
    }
}

char pion::name() const
{
    return 'P';
}

std::unique_ptr<piece> pion::clone() const
{
    return std::make_unique<pion>(*this);
}

