#ifndef POSITION_H
#define POSITION_H
#include <iostream>

using coordonnee = signed int;

class position
{
private:
    coordonnee _horizontal; // A - H
    coordonnee _vertical; // 1 a 8
public:
    position(coordonnee horizontal, coordonnee vertical);
    position(position const &P) = default;
    ~position() = default;
    coordonnee horizontal() const;
    void setHorizontal(coordonnee newHorizontal);
    coordonnee vertical() const;
    void setVertical(coordonnee newVertical);
    position & operator=(position const & P);
    bool operator==(position const & P)const;
    bool operator!=(const position &P)const;
    bool estValide()const;
};

std::ostream & operator<<(std::ostream & os, position const & P);

#endif
