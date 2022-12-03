#ifndef PION_H
#define PION_H
#include "piece.h"


class pion : public piece
{
private:
    bool premierCoup;
public:
    pion(couleur const & C, position const & P);
    unsigned short int valeur() const override;
    void deplacementPossibles() override;
    char name() const override;

    // piece interface
public:
    std::unique_ptr<piece> clone() const;
};

#endif // PION_H
