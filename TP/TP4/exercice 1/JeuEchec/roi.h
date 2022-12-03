#ifndef ROI_H
#define ROI_H
#include "piece.h"


class roi : public piece
{
public:
    roi(const couleur &C, const position &P);
    unsigned short int valeur() const override;
    void deplacementPossibles() override;
    char name() const override;

    // piece interface
public:
    std::unique_ptr<piece> clone() const;
};

#endif // ROI_H
