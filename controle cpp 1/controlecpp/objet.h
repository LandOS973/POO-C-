#ifndef OBJET_H
#define OBJET_H
#include "position.h"
#include "taille.h"

class objet
{
private:
    taille _t;
    position _p;
public:
    objet(const taille &t, const position &p);
    virtual ~objet() = default;
    const position &pos() const;
    void setPos(const position &newP);
    const taille &tai() const;
    void setT(const taille &newT);
    bool contientposition(const position &p) const;
    virtual void sortieflux(std::ostream &os) const;
    virtual void appliquerdeplacement() = 0;
    friend std::ostream & operator<<(std::ostream &os,objet const &S);
};

#endif // OBJET_H
