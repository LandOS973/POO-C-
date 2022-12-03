#include "element.h"

element::element(coordonnee largeur, coordonnee hauteur,coordonnee x, coordonnee y)
    :_taille(largeur,hauteur),_position(x,y){}

taille const & element::getTaille() const{
    return _taille;
}

position const & element::getPosition() const{
    return _position;
}

std::string element::toString() const{
    return _position.toString() + " " + _taille.toString() + " ";
}

bool element::contientPosition(position P) const {
    int x = getTaille().get_hauteur() + getPosition().get_x();
    int y = getTaille().get_largeur() + getPosition().get_y();
    return (P.get_x() >= getPosition().get_x() && P.get_x() <= x) && (P.get_y() >= getPosition().get_y() && P.get_y() <= y);
}

void element::setPostion(coordonnee x, coordonnee y){
    _position.set_x(x);
    _position.set_y(y);
}
