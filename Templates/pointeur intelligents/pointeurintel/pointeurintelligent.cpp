#include "pointeurintelligent.h"

// ################# PRODUIT ###########################

produit::produit(const std::string &nom, float prixHT) : _nom(nom),
    _prixHT(prixHT)
{}

void produit::sortieflux(std::ostream &os) const
{
    os<< _nom <<"\n";
    os<< "Prix HT " << _prixHT <<"\n";
}

// PRODUIT PERISSABLE

const std::string &produitperissable::peremption() const
{
    return _peremption;
}

produitperissable::produitperissable(const std::string &peremption, const std::string &nom, float prixHT) : produit(nom, prixHT),
    _peremption(peremption)
{}

std::unique_ptr<produit> produitperissable::fabriqueUniquePtr(const std::string &peremption, const std::string &nom, float prixHT)
{
    if(prixHT > 0){
        return std::unique_ptr<produit>(new produitperissable(peremption,nom,prixHT));
    }
    return nullptr;
}

std::shared_ptr<produit> produitperissable::fabriqueSharedPtr(const std::string &peremption, const std::string &nom, float prixHT)
{
    if(prixHT > 0){
        return std::shared_ptr<produit>(new produitperissable(peremption,nom,prixHT));
    }
    return nullptr;
}

void produitperissable::sortieflux(std::ostream &os) const
{
    produit::sortieflux(os);
    os<<"date de peremption "<< _peremption<<"\n";
}

std::unique_ptr<produit> produitperissable::cloneUniquePtr() const
{
    return std::make_unique<produitperissable>(*this);
}


std::shared_ptr<produit> produitperissable::cloneSharedPtr() const
{
    return std::make_shared<produitperissable>(*this);
}

// ####################### STOCK ##################################


stock::stock(const stock &s)
{
    for(auto const &p : s._produitsSharedPtr){
        _produitsSharedPtr.push_back(p->cloneSharedPtr());
    }
    for(auto const &p : s._produitsUniquePtr){
        _produitsUniquePtr.push_back(p->cloneUniquePtr());
    }
}

void stock::ajouter(std::unique_ptr<produit> p)
{
    _produitsUniquePtr.push_back(std::move(p));
}

void stock::ajouter(std::shared_ptr<produit> p)
{
    _produitsSharedPtr.push_back(p->cloneSharedPtr());
}

void stock::utilisationDynamicCast() const
{
    // DYNAMIC CAST UNIQUE PTR
    for (auto const & p : _produitsUniquePtr) {
        auto pp = dynamic_cast<produitperissable const*>(p.get());
        if (pp != nullptr){
            std::cout<<pp->peremption();
        }
    }
    // DYNAMIC CAST SHARED PTR
    for (auto const & p : _produitsSharedPtr) {
        auto pp = std::dynamic_pointer_cast<produitperissable>(p);
        if (pp != nullptr){
            std::cout<<pp->peremption();
        }
    }
}

std::ostream & operator<<(std::ostream &os,stock const &S){
    for(auto const &i: S._produitsSharedPtr){
        i->sortieflux(os);
    }
    for(auto const &i: S._produitsUniquePtr){
        i->sortieflux(os);
    }
    return os;
}

stock &stock::operator=(const stock &s)
{
    if(this != &s){
        _produitsSharedPtr.clear();
        _produitsUniquePtr.clear();
        for(auto const &p : s._produitsSharedPtr){
            _produitsSharedPtr.push_back(p->cloneSharedPtr());
        }
        for(auto const &p : s._produitsUniquePtr){
            _produitsUniquePtr.push_back(p->cloneUniquePtr());
        }
    }
    return *this;
}


