#ifndef ENSEMBLEVECTOR_H
#define ENSEMBLEVECTOR_H
#include "ensemble.h"
#include <vector>
#include <iostream>
#include <algorithm>


class ensembleVector: public ensemble
{
private:
    std::vector<int>_entiers;
public:
    ensembleVector();
    ensembleVector(ensembleVector const & E);
    void ajoutSansVerif(int x) override;
    void afficher() const override;
    bool vide() const override;
    bool appartient(int x) const override;
    void enlever(int x) override;
    std::vector<int> const & getEntiers() const;
    int estFini() const override;
    void vider() override;
    int acces(int x) const override;
};

#endif // ENSEMBLEVECTOR_H
