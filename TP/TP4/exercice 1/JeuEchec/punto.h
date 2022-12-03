#ifndef PUNTO_H
#define PUNTO_H
#include "piece.h"

class punto: public piece
{
public:
    punto(const couleur &C, const position &P);
    void deplacer(position const & P) override;
    std::string toString() const override;
    bool peutDeplacer(position const & P) const override;
};

#endif // PUNTO_H
