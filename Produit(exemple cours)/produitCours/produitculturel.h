#ifndef PRODUITCULTUREL_H
#define PRODUITCULTUREL_H
#include "produit.h"

class produitculturel : public produit
{
public:
    produitculturel(const std::string &nom, float prixHT);

    // produit interface
public:
    float tva() const override;
    produit *clone() const override;
    std::unique_ptr<produit> cloneUniquePtr() const override;
};

#endif // PRODUITCULTUREL_H
