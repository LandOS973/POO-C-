#include "objetactif.h"


int objetactif::xmin() const
{
    return _xmin;
}

void objetactif::setXmin(int newXmin)
{
    _xmin = newXmin;
}

int objetactif::xmax() const
{
    return _xmax;
}

void objetactif::setXmax(int newXmax)
{
    _xmax = newXmax;
}

direction objetactif::dir() const
{
    return _d;
}

void objetactif::setDir(direction newD)
{
    _d = newD;
}

void objetactif::appliquerdeplacement()
{
    switch (_d) {
    case direction::droite:
        if(pos().x() + tai().w() != _xmax) setPos(position(pos().x()+1,pos().y()));
        break;
    case direction::gauche:
        if(pos().x() != _xmin) setPos(position(pos().x()-1,pos().y()));
        break;
    default:
        break;
    }
}

objetactif::objetactif(int xmin, int xmax, const direction &d, const taille &t, const position &p) : objet(t, p),
    _xmin(xmin),
    _xmax(xmax),
    _d(d)
{}
