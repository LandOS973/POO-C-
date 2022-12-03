#include "objetramassable.h"


objetramassable::objetramassable(coordonnee largeur, coordonnee hauteur,coordonnee x, coordonnee y,unsigned int points)
    :element(largeur,hauteur,x,y), _points(points)
{

}

unsigned int const & objetramassable::get_points() const {
    return _points;
}

std::string objetramassable::toString() const{
    return element::toString() + " { points : " + std::to_string(get_points()) + " } ";
}
