#include "rectangle.h"

rectangle::rectangle(unsigned short int rouge, unsigned short int bleu,unsigned short int vert,int x2, int y2, int x3, int y3, int x4, int y4)
    :figure(rouge,bleu,vert), _P2(x2,y2), _P3(x3,y3), _P4(x4,y4)
{
    std::cout<<"Constructeur de Rectangle avec point d'origine a (0,0) \n";

}

rectangle::rectangle(unsigned short int rouge, unsigned short int bleu,unsigned short int vert, int x, int y, int x2, int y2, int x3, int y3, int x4, int y4)
    :figure(rouge,bleu,vert,x,y), _P2(x2,y2), _P3(x3,y3), _P4(x4,y4)
{
    std::cout<<"Constructeur de Rectangle avec initialisation du point d'orgine \n";
}

void rectangle::affichage() const{
    std::cout<<"Type de figure : Rectangle { \n    ";
    figure::affichage();
    std::cout<<" P2 ";
    _P2.afficherPoint();
    std::cout<<" P3 ";
    _P3.afficherPoint();
    std::cout<<" P4 ";
    _P4.afficherPoint();
    std::cout<<"\n}\n";
}

void rectangle::translation(point const & P){
    figure::translation(P);
    _P2.translation(P);
    _P3.translation(P);
    _P4.translation(P);
}

bool rectangle::estCarre() const {
    return point::distance(getP(),_P2) == point::distance(_P2,_P3) && point::distance(_P2,_P3) == point::distance(_P3,_P4) && point::distance(_P3,_P4) == point::distance(_P4,getP());
}
