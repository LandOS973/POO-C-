#include "horaire.h"

horaire::horaire(unsigned int mois, unsigned int jour, unsigned int heure):_mois(mois),_jour(jour),_heure(heure){}

horaire::horaire()
{

}

unsigned int horaire::mois() const
{
    return _mois;
}

unsigned int horaire::jour() const
{
    return _jour;
}

unsigned int horaire::heure() const
{
    return _heure;
}

std::string horaire::tostring() const
{
    return std::to_string(_jour) + "/" + std::to_string(_mois) + "-" + std::to_string(_heure) + "h.";
}
