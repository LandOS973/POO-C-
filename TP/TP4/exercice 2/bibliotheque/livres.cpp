#include "livres.h"

livres::livres(bool emprunt, unsigned int nbpages, const std::string &nomAuteur, const std::string &titre) : documentecrit(nbpages, nomAuteur, titre),
    emprunt(emprunt)
{}

bool livres::empruntable() const
{
    return emprunt;
}

std::string livres::type() const
{
    return "livre";
}

document *livres::clone() const
{
    return new livres(*this);
}
