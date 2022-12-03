#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"

class triangle : public figure
{
private:
    point _P1;
    point _P2;
public:
    triangle(unsigned short int rouge, unsigned short int bleu,unsigned short int vert,int x0, int y0,int x1, int y1,int x2, int y2);
    triangle(unsigned short int rouge, unsigned short int bleu,unsigned short int vert, int x, int y, int x2, int y2);
    void translation(point const & P) override;
    void affichage()const override;
};

#endif // TRIANGLE_H
