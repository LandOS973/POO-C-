#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
#include <list>
#include <string>


/*Cette classe comportera comme attributs :
un identifiant du sommet (de type identifiant, équivalent à unsigned int) : cet identifiant unique
sera attribué automatiquement à la construction (sans être passé au constructeur) ;
une étiquette de sommet (une chaîne de caractères) ;
une std::list d’arcs sortants. Pour cela, on déclarera un type structuré arcsortant composé de
l’étiquette de l’arc (une chaîne) et l’extrémité de l’arc (un identifiant).*/

struct arcsortant
{
    std::string etiquette;
    int extremite;
};

class sommet
{
private:
    static int count;
    int _id;
    std::string _etiquette;
    std::list<arcsortant>_arcsortants;
public:
    sommet();
    sommet(const std::string &etiquette);
    static int getCount();
    int id() const;
    const std::string &etiquette() const;
    void ajouterarc(int id, const std::string &etiquette);
    /*supprimerarc prenant comme paramètre un identifiant de sommet et supprimant l’arc sortant vers ce
sommet (s’il existe, ne faisant rien sinon).*/
    void supprimerarc(int id);
    void toutsupprimer();
    void dot_etiquette(std::ostream &os) const;
};

#endif // SOMMET_H
