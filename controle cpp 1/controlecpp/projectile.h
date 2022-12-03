#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "objet.h"

class projectile : public objet
{
public:
    projectile(const position &p);

    // objet interface
public:
    void sortieflux(std::ostream &os) const override;
    void appliquerdeplacement() override;
};

#endif // PROJECTILE_H
