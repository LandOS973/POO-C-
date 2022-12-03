#include "datereleve.h"

datereleve::datereleve(date mois, date jour, date heure, date annee) : _mois(mois),
    _jour(jour),
    _heure(heure),
    _annee(annee)
{}


std::string datereleve::tostring() const
{
    return std::to_string(_jour)+"."+std::to_string(_mois)+"."+std::to_string(_annee)+" "+std::to_string(_heure)+"h";
}

bool datereleve::comparememejour(const datereleve &D1, const datereleve &D2)
{
    return D1 == D2;
}

bool datereleve::compareavant(const datereleve &D1, const datereleve &D2)
{
    if(D2._annee > D1._annee) return true;
    if(D2._annee < D1._annee) return false;
    if(D2._mois > D1._mois) return true;
    if(D2._mois < D1._mois) return false;
    if(D2._heure > D1._heure) return true;
    if(D2._heure < D1._heure) return false;
    return false;
}

bool datereleve::operator==(const datereleve &D) const
{
    return _heure == D._heure && _jour == D._jour && _mois == D._mois;
}
