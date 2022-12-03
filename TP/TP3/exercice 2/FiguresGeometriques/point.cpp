#include "point.h"
#include <iostream>
#include <cmath>  // <cmath> en C++

point::point() : _x(0), _y(0){
    std::cout<<"Constructeur de point par defaut \n";
}

point::point(int x, int y) : _x(x), _y(y)
{
    std::cout<<"Constructeur de point avec params \n";
}

point::point(point const & P) : _x(P._x), _y(P._y) {
    std::cout<<"Constreur de point par recopie\n";
}

point::~point(){
    std::cout<<"Destructeur de point\n";
}

int const & point::getX() const {
    return _x;
}
int const & point::getY() const {
    return _y;
}

void point::setX(int x) {
    _x = x;
}

void point::setY(int y) {
    _y = y;
}

void point::translation(point const & P) {
    _x += P.getX();
    _y += P.getY();
}

void point::afficherPoint() const {
    std::cout<<"{ x : " << getX() << " y : " << getY()<<" } ";
}

double point::distance(point const & P1, point const & P2){
    return sqrt(pow(P2.getX()-P1.getX(),2) - pow(P2.getY() - P1.getY(),2));
}

