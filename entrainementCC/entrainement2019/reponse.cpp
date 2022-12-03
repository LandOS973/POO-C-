#include "reponse.h"

reponse::reponse(const std::string &expediteur, const std::vector<std::string> &destinataire,const proposition &P,const horaire &H)
    : message(expediteur, destinataire), _idProp(P.id()), _H(H){}

void reponse::sortieflux(std::ostream &os) const
{
    std::string destinataires;
    for(auto i : destinataire()){
        destinataires += i + " ";
    }
    os<<id()<<" "<<expediteur()<<"->"<<destinataires<<" REPONSE A "<<_idProp<<" : "<<_H.tostring()<<"\n";
}

bool reponse::reuniondate(unsigned int jour, unsigned int mois) const
{
    return jour == _H.heure() && mois == _H.mois();
}
