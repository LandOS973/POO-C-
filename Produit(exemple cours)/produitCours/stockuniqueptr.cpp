#include "stockuniqueptr.h"
#include "produitperissable.h"

stockuniqueptr::stockuniqueptr()
{

}

stockuniqueptr::stockuniqueptr(const stockuniqueptr &s)
{
    for(auto const &p : s._produits){
        _produits.push_back(p->cloneUniquePtr());
    }
}

void stockuniqueptr::ajouter(std::unique_ptr<produit> p)
{
    _produits.push_back(std::move(p));
}

void stockuniqueptr::afficher() const
{
    for(auto const &p : _produits){
        p->afficher();
    }
}

void stockuniqueptr::afficherperemption() const
{
    for(auto const &p : _produits){
        auto pp = dynamic_cast<produitperissable const *>(p.get());
        if(pp != nullptr) std::cout<<pp->peremption();
    }
}

stockuniqueptr &stockuniqueptr::operator=(const stockuniqueptr &s)
{
    if(this != &s){
        _produits.clear();
        for(auto const &p : s._produits){
            _produits.push_back(p->cloneUniquePtr());
        }
    }
    return *this;
}

bool stockuniqueptr::operator==(const stockuniqueptr &s) const
{
    if(_produits.size() != s._produits.size()) return false;
    for (std::vector<int>::size_type i(0); i<_produits.size(); ++i){
        if(_produits[i]->nom() != s._produits[i]->nom()) return false;
        if(_produits[i]->prixHT() != s._produits[i]->prixHT()) return false;
    }
    return true;
}

float stockuniqueptr::tvaMoyen() const
{
    float tvamoyen = 0;
    for(auto const &p : _produits){
        tvamoyen += p->tva();
    }
    return tvamoyen / _produits.size();
}

std::ostream & operator<<(std::ostream &os,stockuniqueptr const &S){
    for(auto const &p: S._produits){
        p->sortie(os);
    }
    return os;
}
