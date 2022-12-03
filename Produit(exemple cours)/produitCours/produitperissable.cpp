#include "produitperissable.h"

const std::string &produitperissable::peremption() const
{
    return _peremption;
}

float produitperissable::tva() const
{
    return 0.2;
}

produitperissable::produitperissable(const std::string &peremption, const std::string &nom, float prixHT) : produit(nom, prixHT),
    _peremption(peremption)
{}

void produitperissable::afficher() const
{
    produit::afficher();
    std::cout<<"date de peremption "<<peremption()<<"\n";
}

produit *produitperissable::clone() const
{
    return new produitperissable(*this);
}

void produitperissable::sortie(std::ostream &os) const
{
    produit::sortie(os);
    os<<"date de peremption "<<peremption()<<"\n";
}

std::unique_ptr<produit> produitperissable::cloneUniquePtr() const
{
    return std::make_unique<produitperissable>(*this);
}


