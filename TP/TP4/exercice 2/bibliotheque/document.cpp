#include "document.h"

document::document(const std::string &nomAuteur, const std::string &titre) : nomAuteur(nomAuteur),
    titre(titre)
{}

void document::sortie(std::ostream &os) const
{
    os<<"Titre : "<<titre<<" Nom de l'auteur : "<<nomAuteur<<" Empruntable : "<<empruntable()<<" Type : "<<type()<< " Cout : "<<cout();
}

std::ostream & operator<<(std::ostream &os,document const &S){
    S.sortie(os);
    return os;
}
