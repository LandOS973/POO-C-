#ifndef OBJETRAMASSABLE_H
#define OBJETRAMASSABLE_H
#include "element.h"

class objetramassable : public element
{
private:
    unsigned int _points;
public:
    objetramassable(coordonnee largeur, coordonnee hauteur,coordonnee x, coordonnee y,unsigned int points);
    unsigned int const & get_points() const;
    std::string toString() const override;
};

#endif // OBJETRAMASSABLE_H
