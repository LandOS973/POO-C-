#ifndef DAME_H
#define DAME_H
#include "piece.h"

class dame: public piece
{
public:
    dame(const couleur &C, const position &P);
    unsigned short int valeur() const override;
    void deplacementPossibles() override;
    char name() const override;

    // piece interface
public:
    std::unique_ptr<piece> clone() const;
};

#endif // DAME_H
