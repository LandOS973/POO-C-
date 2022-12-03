#ifndef ENSEMBLE_H
#define ENSEMBLE_H
#include <iostream>
#include "parcours.h"

class ensemble
{
protected:
    virtual void ajoutSansVerif(int x) = 0;
public:
    void ajout(int x);
    ~ensemble() = default;
    virtual int acces(int x) const = 0;
    virtual void afficher() const = 0;
    virtual bool vide() const = 0;
    virtual bool appartient(int x) const = 0;
    virtual void enlever(int x) = 0;
    virtual int estFini() const = 0;
    virtual void vider() = 0;
    void unionE(ensemble & E1, ensemble & E2);
    void intersection(ensemble & E1, ensemble & E2);
};




#endif // ENSEMBLE_H
