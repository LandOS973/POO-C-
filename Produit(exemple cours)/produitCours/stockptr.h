#ifndef STOCKPTR_H
#define STOCKPTR_H
#include <vector>
#include "produit.h"

class stockptr
{
private:
    std::vector<produit *>_produits;
public:
    stockptr();
    stockptr(const stockptr &S);
    ~stockptr();
    stockptr &operator=(const stockptr & s);
    bool operator==(const stockptr &s) const;
    void afficher() const;
    void afficherperemption() const;
    float tvaMoyen() const;
    void ajouter(const produit &p);
    friend std::ostream & operator<<(std::ostream &os,stockptr const &S);
};

#endif // STOCKPTR_H
