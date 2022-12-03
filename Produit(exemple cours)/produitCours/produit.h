#ifndef PRODUIT_H
#define PRODUIT_H
#include <string>
#include <iostream>
#include <memory>

class produit
{
private:
    static unsigned int _compteur;
    unsigned int _ref;
    std::string _nom;
    float _prixHT;
public:
    bool operator==(const produit &p) const;
    produit(const std::string &nom, float prixHT);
    unsigned int ref() const;
    const std::string &nom() const;
    float prixHT() const;
    virtual void afficher() const;
    virtual float tva() const = 0;
    float prixTTC() const;
    virtual produit * clone() const =0;
    virtual std::unique_ptr<produit>cloneUniquePtr() const =0;
    virtual void sortie(std::ostream &os) const;
};

#endif // PRODUIT_H
