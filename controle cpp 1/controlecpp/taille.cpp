#include "taille.h"


unsigned int taille::h() const
{
    return _h;
}

unsigned int taille::w() const
{
    return _w;
}

void taille::setW(unsigned int newW)
{
    _w = newW;
}

taille::taille(unsigned int h, unsigned int w) : _h(h),
    _w(w)
{}
