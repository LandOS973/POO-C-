#include "horaire.h"

date horaire::getMois() const
{
    return mois;
}

date horaire::getJour() const
{
    return jour;
}

date horaire::getHeure() const
{
    return heure;
}

horaire::horaire(date mois, date jour, date heure) : mois(mois),
    jour(jour),
    heure(heure)
{}
// 14/11-15h.
std::string horaire::tostring() const
{
    return std::to_string(jour) + "/" + std::to_string(mois) + "-" + std::to_string(heure) + "h.";
}
