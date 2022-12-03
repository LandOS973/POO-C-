#ifndef ELEMENT_H
#define ELEMENT_H
#include "tailleposition.h"
#include <iostream>

class element
{
private:
    taille _taille;
    position _position;
public:
    element(coordonnee largeur, coordonnee hauteur,coordonnee x, coordonnee y);
    taille const & getTaille() const;
    position const & getPosition() const;
    void setPostion(coordonnee x,coordonnee y);
    virtual std::string toString() const;
    bool contientPosition(position P) const;
};

#endif // ELEMENT_H
