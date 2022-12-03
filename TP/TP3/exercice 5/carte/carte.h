#ifndef CARTE_H
#define CARTE_H
#include <list>
#include "tailleposition.h"
#include "obstacle.h"
#include "personnage.h"
#include "objetramassable.h"

class carte
{
private:
    taille _taille;
    std::list<obstable> _obstables;
    std::list<personnage> _personnages;
    std::list<objetramassable> _objets;
private:
    bool intersection(const element &A,const element &B) const;
    bool peutAjouter(const element &E) const;
    void majListeDesPerso(const personnage &P);
public:
    carte(int x, int y);
    void ajout(const obstable & O);
    void ajout(const personnage & P);
    void ajout(const objetramassable & O);
    void afficher() const;
    bool deplacer(personnage &P, int x,int y);
    void ramasserObj(personnage &P);
};

#endif // CARTE_H
