#ifndef PRODUITPERISSABLE_H
#define PRODUITPERISSABLE_H
#include "produit.h"

class produitperissable : public produit
{
private:
    std::string _peremption;

public:
    produitperissable(const std::string &peremption, const std::string &nom, float prixHT);
    const std::string &peremption() const;

    // produit interface
public:
    float tva() const override;
    void afficher() const override;
    produit *clone() const override;
    void sortie(std::ostream &os) const override;
    std::unique_ptr<produit> cloneUniquePtr() const override;
};

#endif // PRODUITPERISSABLE_H
