#include "documentecrit.h"

documentecrit::documentecrit(unsigned int nbpages, const std::string &nomAuteur, const std::string &titre) : document(nomAuteur, titre),
    _nbpages(nbpages)
{}

float documentecrit::cout() const
{
    return 0.5 * _nbpages;
}

void documentecrit::sortie(std::ostream &os) const
{
    document::sortie(os);
    os<<" nombre de page : "<<_nbpages;
}
