#pragma once
#include <memory>
#include <string>
#include <iostream>
#include <vector>

// ################################# PRODUITS #######################################

class produit
{
private:
    std::string _nom;
    float _prixHT;
    // CONSTRUCTEUR PRIVE => fabrique pour creer
    produit(const std::string &nom, float prixHT);
public:
    ~produit() = default;
    // UNIQUE PTR
    virtual std::unique_ptr<produit>cloneUniquePtr() const =0;
    // SHARED PTR
    virtual std::shared_ptr<produit>cloneSharedPtr() const = 0;
    virtual void sortieflux(std::ostream &os) const;
    // PRODUIT PERISSABLE PEUT ACCEDER A PRODUIT
    friend class produitperissable;
};

// PRODUIT PERRISSABLE <= PRODUIT

class produitperissable : public produit
{
private:
    std::string _peremption;
    // CONSTRUCTEUR PRIVE => Fabriques pour creer
    produitperissable(const std::string &peremption, const std::string &nom, float prixHT);
public:
    // CONSTRUCTEURS
    static std::unique_ptr<produit>fabriqueUniquePtr(const std::string &peremption, const std::string &nom, float prixHT);
    static std::shared_ptr<produit>fabriqueSharedPtr(const std::string &peremption, const std::string &nom, float prixHT);
    void sortieflux(std::ostream &os) const override;
    // UNIQUE PTR
    std::unique_ptr<produit> cloneUniquePtr() const override;
    // SHARED PTR
    std::shared_ptr<produit> cloneSharedPtr() const override;
    const std::string &peremption() const;
};

// ##################################### STOCK ####################################

class stock
{
private:
    std::vector<std::unique_ptr <produit>> _produitsUniquePtr;
    std::vector<std::shared_ptr <produit>> _produitsSharedPtr;
public:
    stock(){}
    stock(stock const &s);
    stock &operator=(const stock &s);
    ~stock() = default;
    void ajouter(std::unique_ptr<produit> p);
    void ajouterUniquePtrConvertitEnSharedPtr(std::unique_ptr<produit> p);
    void ajouter(std::shared_ptr<produit> p);
    void utilisationDynamicCast()const;
    // sortie <<
    friend std::ostream & operator<<(std::ostream &os,stock const &S);
};









