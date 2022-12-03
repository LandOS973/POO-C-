#include "punto.h"

punto::punto(const couleur &C, const position &P) : piece(C, P){}

std::string punto::toString() const
{
    return "P" + piece::toString();
}

