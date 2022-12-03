#include "projectile.h"

projectile::projectile(const position &p) : objet(taille(1,1), p)
{}

void projectile::sortieflux(std::ostream &os) const
{
    os<<"P";
    objet::sortieflux(os);
}

void projectile::appliquerdeplacement()
{
    if(pos().y() > 0) setPos(position(pos().x(),pos().y()-1));
}
