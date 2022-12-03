#include "position.h"

unsigned int position::x() const
{
    return _x;
}

void position::setX(unsigned int newX)
{
    _x = newX;
}

unsigned int position::y() const
{
    return _y;
}

void position::setY(unsigned int newY)
{
    _y = newY;
}

bool position::operator==(const position &p) const
{
    return p._x == _x && p._y == _y;
}

bool position::operator!=(const position &p) const
{
    return p._x != _x || p._y != _y;
}

std::string position::tostring() const
{
    return "(" + std::to_string(_x) +"," + std::to_string(_y) + ")";
}

position::position(unsigned int x, unsigned int y) : _x(x),
    _y(y)
{}



std::ostream & operator<<(std::ostream &os,position const &S){
    os<<S.tostring();
    return os;
}
