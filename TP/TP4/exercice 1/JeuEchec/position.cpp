#include "position.h"

position::position(coordonnee horizontal, coordonnee vertical): _horizontal(horizontal), _vertical(vertical){}

coordonnee position::horizontal() const
{
    return _horizontal;
}

void position::setHorizontal(coordonnee newHorizontal)
{
    _horizontal = newHorizontal;
}

coordonnee position::vertical() const
{
    return _vertical;
}

void position::setVertical(coordonnee newVertical)
{
    _vertical = newVertical;
}

position &position::operator=(const position &P)
{
    if(this != &P){
        _horizontal = P.horizontal();
        _vertical = P.vertical();
    }
    return *this;
}

bool position::operator==(const position &P)const
{
    return _horizontal == P.horizontal() && _vertical == P.vertical();
}

bool position::operator!=(const position &P)const
{
    return _horizontal != P.horizontal() || _vertical != P.vertical();
}

bool position::estValide() const
{
    return _horizontal <= 8 && _horizontal >= 1 && _vertical >= 1 && _vertical <= 8;
}

std::ostream & operator<<(std::ostream & os, position const & P){
    os<<char(P.horizontal()+64)<<P.vertical()<<" ";
    return os;
}


