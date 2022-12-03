#include "produit.h"

unsigned int produit::_compteur(0);

unsigned int produit::ref() const
{
    return _ref;
}

const std::string &produit::nom() const
{
    return _nom;
}

float produit::prixHT() const
{
    return _prixHT;
}

void produit::afficher() const
{
    std::cout<< _ref << " " << _nom <<"\n";
    std::cout<< "Prix HT " << _prixHT <<"\n";
    std::cout<< "Prix TTC " << prixTTC() <<"\n";
}

float produit::prixTTC() const
{
    return _prixHT + _prixHT * tva();
}

void produit::sortie(std::ostream &os) const
{
    os<< _ref << " " << _nom <<"\n";
    os<< "Prix HT " << _prixHT <<"\n";
    os<< "Prix TTC " << prixTTC() <<"\n";
}

bool produit::operator==(const produit &p) const
{
    return p.ref() == ref() && p.nom() == nom();
}

produit::produit(const std::string &nom, float prixHT): _ref(_compteur++), _nom(nom), _prixHT(prixHT){}
