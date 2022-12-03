#ifndef GRAPHE_H
#define GRAPHE_H
#include <iostream>
#include "sommet.h"

class graphe
{
private:
    std::list<sommet> _sommets;
public:
    graphe();
    identifiant ajoutersommet(std::string etiquette);
    bool ajouterarc(identifiant a, identifiant b, std::string etiquette);
    void supprimersommet(identifiant id);
    void dot_sortie(std::ostream & out) const;
};

#endif // GRAPHE_H
