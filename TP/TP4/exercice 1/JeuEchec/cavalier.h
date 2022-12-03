#ifndef CAVALIER_H
#define CAVALIER_H
#include "piece.h"

class cavalier: public piece
{
public:
    cavalier(const couleur &C, const position &P);
    unsigned short int valeur() const override;
    void deplacementPossibles() override;
    char name() const override;

    // piece interface
public:
    std::unique_ptr<piece> clone() const;
};

#endif // CAVALIER_H
