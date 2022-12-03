#include "stockvectors.h"

stockvectors::stockvectors()
{

}

void stockvectors::afficher() const
{
    for(auto const & i : _pcs){
        i.afficher();
    }
    for(auto const & i: _pps){
        i.afficher();
    }
}

void stockvectors::afficherperemption() const
{
    for(auto const & i : _pps){
        i.peremption();
    }
}

float stockvectors::tvaMoyen() const
{
    int count = 0;
    for(auto const & i : _pcs){
        count += i.tva();
    }
    for(auto const & i: _pps){
        count += i.tva();
    }
    return count / (_pcs.size() + _pps.size());
}

void stockvectors::ajouter(const produitperissable &p)
{
    _pps.push_back(p);
}

void stockvectors::ajouter(const produitculturel &p)
{
    _pcs.push_back(p);
}

std::ostream & operator<<(std::ostream &os,stockvectors const &S){
    for(auto const & i : S._pcs){
        i.sortie(os);
    }
    for(auto const & i: S._pps){
        i.sortie(os);
    }
    return os;
}
