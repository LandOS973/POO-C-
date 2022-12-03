#ifndef JOUEUR_H
#define JOUEUR_H
#include "objetactif.h"

class joueur : public objetactif
{
public:
    joueur(int xmin, int xmax, const direction &d, const taille &t, const position &p);
    void mallus();
    void bonus();

    // objet interface
public:
    void sortieflux(std::ostream &os) const override;
};

#endif // JOUEUR_H
