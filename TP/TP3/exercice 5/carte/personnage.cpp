#include "personnage.h"
#include <iostream>

void personnage::setPoints(unsigned int newPoints)
{
    _points = newPoints;
}

unsigned int personnage::points() const
{
    return _points;
}

personnage::personnage(coordonnee largeur, coordonnee hauteur,coordonnee x, coordonnee y, std::string nom)
    : element(largeur,hauteur,x,y), _points(0), _nom(nom)
{

}

void personnage::seDeplacer(coordonnee const x, coordonnee const y){
    setPostion(x,y);
}

void personnage::ramasserObjet(objetramassable const & O){
    _points += O.get_points();
}

std::string const & personnage::get_nom() const {
    return _nom;
}

std::string personnage::toString() const{
    return element::toString() + "Caracteristique { nom: " + get_nom() + " points: " + std::to_string(_points) + " } ";
}
