#include "precipitation.h"


const type &precipitation::prec() const
{
    return _prec;
}

precipitation::precipitation(const type &prec, int quantite, const datereleve &d) : releve(d),
    _prec(prec),
    _quantite(quantite)
{}

std::string precipitation::tostring() const
{
    std::string s;
    switch (_prec) {
    case type::grele: s = "grele";break;
    case type::neige: s = "neige";break;
    case type::pluie: s = "pluie";break;
    default:break;
    }
    return releve::tostring() + " " + s + " " + std::to_string(_quantite) + "mm";
}

std::string precipitation::typereleve() const
{
    return "precipitation";
}

releve *precipitation::clone() const
{
    return new precipitation(*this);
}
