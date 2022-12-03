#ifndef STOCKUNIQUEPTR_H
#define STOCKUNIQUEPTR_H
#include "produit.h"
#include <vector>
#include <memory>

class stockuniqueptr
{
private:
    std::vector<std::unique_ptr <produit>> _produits;
public:
    stockuniqueptr();
    stockuniqueptr(const stockuniqueptr &s);
    ~stockuniqueptr() = default;
    stockuniqueptr &operator=(const stockuniqueptr &s);
    bool operator==(const stockuniqueptr &s) const;
    void afficher() const;
    void afficherperemption() const;
    float tvaMoyen() const;
    void ajouter(std::unique_ptr<produit> p);
    friend std::ostream & operator<<(std::ostream &os,stockuniqueptr const &S);
};

#endif // STOCKUNIQUEPTR_H
