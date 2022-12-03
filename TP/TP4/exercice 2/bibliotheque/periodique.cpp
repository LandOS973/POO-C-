#include "periodique.h"



bool periodique::empruntable() const
{
    return true;
}

std::string periodique::type() const
{
    return "periodique";
}

void periodique::sortie(std::ostream &os) const
{
    document::sortie(os);
    os<<" numero du periodique : "<<_numero;
}

document *periodique::clone() const
{
    return new periodique(*this);
}


periodique::periodique(int numero, unsigned int nbpages, const std::string &nomAuteur, const std::string &titre) : documentecrit(nbpages, nomAuteur, titre),
    _numero(numero)
{}
