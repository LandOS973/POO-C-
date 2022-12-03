#include "proposition.h"

const std::list<horaire> &proposition::getHoraires() const
{
    return horaires;
}

const std::string &proposition::getDescription() const
{
    return description;
}

proposition::proposition(const std::list<horaire> &horaires, const std::string &description, const std::string &expediteur, const std::vector<std::string> &destinataire)
    : message(expediteur, destinataire),
    horaires(horaires),
    description(description)
{}

void proposition::sortieflux(std::ostream &os) const
{
    std::string destinataires;
    for(auto i : destinataire()){
        destinataires += i + " ";
    }
    std::string hprop;
    for(auto e : horaires){
        hprop += e.tostring() + " ";
    }
    os<<id()<<" "<<expediteur()<<"->"<<destinataires<<" PROPOSITION "<<description<<" : "<<hprop<<"\n";
}

bool proposition::reuniondate(unsigned int jour, unsigned int mois) const
{
    for(auto i : horaires){
        if(jour == i.jour() && mois == i.mois()) return true;
    }
    return false;
}
