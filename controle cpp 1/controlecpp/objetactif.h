#ifndef OBJETACTIF_H
#define OBJETACTIF_H
#include "objet.h"

enum class direction{
    stop,droite,gauche
};

class objetactif : public objet
{
private:
    int _xmin;
    int _xmax;
    direction _d;
public:
    objetactif(int xmin, int xmax, const direction &d, const taille &t, const position &p);

    int xmin() const;
    void setXmin(int newXmin);
    int xmax() const;
    void setXmax(int newXmax);
    direction dir() const;
    void setDir(direction newD);

    // objet interface
public:
    void appliquerdeplacement() override;
};

#endif // OBJETACTIF_H
