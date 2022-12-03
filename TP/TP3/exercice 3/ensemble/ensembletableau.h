#ifndef ENSEMBLETABLEAU_H
#define ENSEMBLETABLEAU_H
#include "ensemble.h"
#include <iostream>

class ensembleTableau : public ensemble
{
private:
    int * _entiers;
    std::size_t _taille;
public:
    ensembleTableau();
    ensembleTableau(ensembleTableau const & E);
    ~ensembleTableau();
    void afficher() const override;
    bool vide() const override;
    void ajoutSansVerif(int x) override;
    bool appartient(int x) const override;
    void enlever(int x) override;
    int * const & getEntiers() const;
    int estFini() const override;
    void vider() override;
    int acces(int x) const override;
};

#endif // ENSEMBLETABLEAU_H
