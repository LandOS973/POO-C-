#ifndef TOUR_H
#define TOUR_H
#include "piece.h"

class tour: public piece
{
public:
    tour(const couleur &C, const position &P);
    unsigned short int valeur() const override;
    void deplacementPossibles() override;
    char name() const override;

    // piece interface
public:
    std::unique_ptr<piece> clone() const;
};

#endif // TOUR_H
