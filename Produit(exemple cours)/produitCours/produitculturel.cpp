#include "produitculturel.h"

produitculturel::produitculturel(const std::string &nom, float prixHT) : produit(nom, prixHT)
{}

float produitculturel::tva() const
{
    return 0.055;
}

produit *produitculturel::clone() const
{
    return new produitculturel(*this);
}

std::unique_ptr<produit> produitculturel::cloneUniquePtr() const
{
    return std::make_unique<produitculturel>(*this);
}
