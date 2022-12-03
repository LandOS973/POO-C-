#include "joueur.h"


joueur::joueur(int xmin, int xmax, const direction &d, const taille &t, const position &p) : objetactif(xmin, xmax, d, t, p)
{}

void joueur::mallus()
{
    int largeur = tai().w() * 2;
    if(largeur >100) largeur =100;
    setT(taille(tai().h(),largeur));
}

void joueur::bonus()
{
    int largeur = tai().w() / 2;
    if(largeur < 3) largeur = 3;
    setT(taille(tai().h(),largeur));
}

void joueur::sortieflux(std::ostream &os) const
{
    os<<"J";
    objet::sortieflux(os);
}
