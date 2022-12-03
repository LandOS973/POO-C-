#ifndef GRAPHE_H
#define GRAPHE_H
#include <list>
#include <iostream>
#include "sommet.h"

class graphe
{
private:
    std::list<sommet>_sommets;
public:
    graphe();
    int ajoutersommet(const std::string etiquette);
    bool ajouterarc(int id1, int id2, const std::string &etiquette);
    void dot_sortie(std::ostream &os) const;
    void supprimersommet(int id);
};

#endif // GRAPHE_H
