#ifndef SEGMENT_H
#define SEGMENT_H
#include "figure.h"


class segment: public figure
{
private:
    point _extremite;
public:
    segment(unsigned short int rouge, unsigned short int bleu,unsigned short int vert,int x, int y);
    segment(unsigned short int rouge, unsigned short int bleu,unsigned short int vert, int x, int y, int x2, int y2);
    void affichage() const override;
    void translation(point const & P) override;
};

#endif // SEGMENT_H
