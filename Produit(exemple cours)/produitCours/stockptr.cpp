#include "stockptr.h"
#include "produitperissable.h"
#include <iostream>

stockptr::stockptr(){}

stockptr::stockptr(const stockptr &S)
{
    for(const auto &p : S._produits){
        _produits.push_back(p->clone());
    }
}

stockptr::~stockptr()
{
    for(auto p : _produits){
        delete p;
    }
}

stockptr &stockptr::operator=(const stockptr &s)
{
    if(this != &s){
        for(auto p: _produits){
            delete p;
        }
        _produits.clear();
        for(auto const &p : s._produits){
            _produits.push_back(p->clone());
        }
    }
    return *this;
}

bool stockptr::operator==(const stockptr &s) const
{
    if(_produits.size() != s._produits.size()) return false;
    for (std::vector<int>::size_type i(0); i<_produits.size(); ++i){
        if(_produits[i]->nom() != s._produits[i]->nom()) return false;
        if(_produits[i]->prixHT() != s._produits[i]->prixHT()) return false;
    }
    return true;
}

void stockptr::afficher() const
{
    for(auto const &p : _produits){
        p->afficher();
    }
}

void stockptr::afficherperemption() const
{
    for(auto const &p : _produits){
        auto pp = dynamic_cast<produitperissable const *>(p);
        if(pp != nullptr) std::cout<<pp->peremption();
    }
}

float stockptr::tvaMoyen() const
{
    float tvamoyen = 0;
    for(auto const &p : _produits){
        tvamoyen += p->tva();
    }
    return tvamoyen / _produits.size();
}

void stockptr::ajouter(produit const & p)
{
    _produits.push_back(p.clone());
}

std::ostream & operator<<(std::ostream &os,stockptr const &S){
    for(auto const &p: S._produits){
        p->sortie(os);
    }
    return os;
}
