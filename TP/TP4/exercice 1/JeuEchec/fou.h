#ifndef FOU_H
#define FOU_H
#include "piece.h"

class fou: public piece
{
public:
    fou(const couleur &C, const position &P);
    unsigned short int valeur() const override;
    void deplacementPossibles() override;
    char name() const override;

    // piece interface
public:
    std::unique_ptr<piece> clone() const;
};

#endif // FOU_H
