#include "invader.h"

invader::invader(int xmin, int xmax, const direction &d, const position &p) : objetactif(xmin, xmax, d, taille(11,8), p)
{}

void invader::sortieflux(std::ostream &os) const
{
    os<<"I";
    objet::sortieflux(os);
}

void invader::appliquerdeplacement()
{
    switch (dir()) {
    case direction::droite:
        if(pos().x() + tai().w() != xmax()) setPos(position(pos().x()+1,pos().y()));
        break;
    case direction::gauche:
        if(pos().x() != xmin()) {
            setPos(position(pos().x()-1,pos().y()));
        }else{
            setPos(position(xmax(),pos().y()+1));
        }
        break;
    default:
        break;
    }
}
