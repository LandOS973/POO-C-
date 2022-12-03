#ifndef FIGURE_H
#define FIGURE_H
#include "couleur.h"
#include "point.h"


class figure
{
private:
    couleur _c;
    point _p;
public:
    figure(unsigned short int rouge, unsigned short int bleu,unsigned short int vert);
    figure(unsigned short int rouge, unsigned short int bleu,unsigned short int vert,int x, int y);
    point const & getP() const;
    virtual void affichage() const;
    virtual void translation(point const & P);
    bool memeOrigine(figure const & F) const;
};

#endif // FIGURE_H
