#include "texte.h"

texte::texte(const std::string &text, const std::string &expediteur, const std::vector<std::string> &destinataire) : message(expediteur, destinataire),
    _text(text)
{}

void texte::sortieflux(std::ostream &os) const
{
    std::string destinataires;
    for(auto i : destinataire()){
        destinataires += i + " ";
    }
    os<<id()<<" "<<expediteur()<<"->"<<destinataires<<" TEXTE "<<_text<<"\n";
}
