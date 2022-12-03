#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "element.h"
#include "objetramassable.h"
#include <iostream>


class personnage : public element
{
private:
    std::string _nom;
    unsigned int _points;
public:
    personnage(coordonnee largeur, coordonnee hauteur,coordonnee x, coordonnee y,std::string nom);
    void ramasserObjet(objetramassable const & O);
    void seDeplacer(int x, int y);
    std::string const & get_nom() const;
    std::string toString() const override;
};

#endif // PERSONNAGE_H
