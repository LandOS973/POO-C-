#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
#include <list>

using identifiant = unsigned int;

struct arc{
    std::string etiquette;
    identifiant extremite;
};

class sommet
{
private:
    std::list<arc> _arcs;
    static int _compteur;
    identifiant _id;
    std::string _etiquette;
public:
    sommet(std::string etiquette);
    unsigned int id() const;
    const std::string &etiquette() const;
    void ajouterArc(identifiant id, const std::string &etiquette);
    void supprimerarc(identifiant id);
    void supprimertousarcs();
    void dot_etiquette(std::ostream & out) const;
    void dot_arcsortant(std::ostream & out) const;
    const std::list<arc> &arcs() const;
};

#endif // SOMMET_H
