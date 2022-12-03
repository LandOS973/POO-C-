#include "segment.h"

segment::segment(unsigned short int rouge, unsigned short int bleu,unsigned short int vert, int x, int y)
    :figure(rouge,bleu,vert),_extremite(x,y)
{
    std::cout<<"Constructeur de segment \n";
}

segment::segment(unsigned short int rouge, unsigned short int bleu,unsigned short int vert, int x, int y, int x2, int y2)
    :figure(rouge,bleu,vert,x,y),_extremite(x2,y2)
{
    std::cout<<"Constructeur de segment avec initialisation des points \n";
}

void segment::affichage() const{
    std::cout<<"Type de figure : segment { \n    ";
    figure::affichage();
    std::cout<<" Point a l'extremite ";
    _extremite.afficherPoint();
    std::cout<<"\n}\n";
}

void segment::translation(point const & P) {
    figure::translation(P);
    _extremite.translation(P);
}
