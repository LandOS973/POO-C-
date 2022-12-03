#ifndef STOCKVECTORS_H
#define STOCKVECTORS_H
#include "produit.h"
#include "produitculturel.h"
#include "produitperissable.h"

#include <vector>


class stockvectors
{
private:
    std::vector<produitculturel>_pcs;
    std::vector<produitperissable>_pps;
public:
    stockvectors();
    void afficher() const;
    void afficherperemption() const;
    float tvaMoyen() const;
    void ajouter(const produitperissable &p);
    void ajouter(const produitculturel &p);
    friend std::ostream & operator<<(std::ostream &os,stockvectors const &S);
};

#endif // STOCKVECTORS_H
