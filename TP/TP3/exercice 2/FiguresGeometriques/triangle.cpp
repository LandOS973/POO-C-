#include "triangle.h"

triangle::triangle(unsigned short int rouge, unsigned short int bleu,unsigned short int vert,int x0, int y0,int x1, int y1,int x2, int y2)
    :figure(rouge,bleu,vert,x0,x1),_P1(x1,y1),_P2(x2,y2)
{
    std::cout<<"Constructeur de triangle avec initialisation du point\n";
}
triangle::triangle(unsigned short int rouge, unsigned short int bleu,unsigned short int vert, int x, int y, int x2, int y2)
    :figure(rouge,bleu,vert),_P1(x,y),_P2(x2,y2)
{
    std::cout<<"Constructeur de triangle\n";
}

void triangle::translation(point const & P){
    figure::translation(P);
    _P1.translation(P);
    _P2.translation(P);
}

void triangle::affichage() const{
    std::cout<<"Type de figure : Rectangle { \n    ";
    figure::affichage();
    std::cout<<" P2 ";
    _P1.afficherPoint();
    std::cout<<" P3 ";
    _P2.afficherPoint();
    std::cout<<"\n}\n";
}
