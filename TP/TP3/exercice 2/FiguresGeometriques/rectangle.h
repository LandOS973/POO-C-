#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"


class rectangle: public figure
{
private:
    point _P2, _P3, _P4;
public:
    rectangle(unsigned short int rouge, unsigned short int bleu,unsigned short int vert,int x, int y, int x2, int y2, int x3, int y3);
    rectangle(unsigned short int rouge, unsigned short int bleu,unsigned short int vert, int x, int y, int x2, int y2, int x3, int y3, int x4, int y4);
    void affichage()const override;
    void translation(point const & P) override;
    bool estCarre() const;
};

#endif // RECTANGLE_H
