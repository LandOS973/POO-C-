#include "tailleposition.h"

// Classe position

position::position(coordonnee x, coordonnee y) : _x(x), _y(y) {};

position::position(position const & P) : _x(P._x) , _y(P._y) {};

coordonnee const & position::get_x() const{
    return _x;
}

void position::set_x(coordonnee const x){
    _x = x;
}

coordonnee const & position::get_y() const {
    return _y;
}

void position::set_y(coordonnee const y) {
    _y = y;
}

bool position::comparaison(position const & P) const {
    return P._x == _x && P._y == _y;
}

std::string position::toString() const{
    return "Position { x: "+ std::to_string(_x) +" y: "+ std::to_string(_y) +" }";
}

// Classe taille

taille::taille(coordonnee largeur, coordonnee hauteur) : _largeur(largeur) , _hauteur(hauteur){};


void taille::set_largeur(coordonnee const largeur){
    _largeur = largeur;
}

void taille::set_hauteur(coordonnee const hauteur){
    _hauteur = hauteur;
}
coordonnee const & taille::get_largeur() const {
    return _largeur;
}
coordonnee const & taille::get_hauteur() const {
    return _hauteur;
}

std::string taille::toString() const{
    return "Taille { Hauteur: " + std::to_string(_hauteur) + " Largeur: "+ std::to_string(_largeur) + " }";
}
