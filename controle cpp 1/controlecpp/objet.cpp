#include "objet.h"


const position &objet::pos() const
{
    return _p;
}

void objet::setPos(const position &newP)
{
    _p = newP;
}

const taille &objet::tai() const
{
    return _t;
}

void objet::setT(const taille &newT)
{
    _t = newT;
}

bool objet::contientposition(const position &p) const
{
    int Lmax = _t.w() + _p.x();
    int Hmax = _t.h() + _p.y();
    return (p.x() > Lmax && p.x() < _p.x()) && (p.y() > Hmax && p.y() <_p.y());
}

void objet::sortieflux(std::ostream &os) const
{
    os<<_p;
}

objet::objet(const taille &t, const position &p) : _t(t),
    _p(p)
{}

std::ostream & operator<<(std::ostream &os,objet const &S){
    S.sortieflux(os);
    return os;
}

