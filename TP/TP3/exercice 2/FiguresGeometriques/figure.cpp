#include "figure.h"
#include <iostream>

figure::figure(unsigned short int rouge, unsigned short int bleu,unsigned short int vert)
    :_c(rouge,bleu,vert),_p()
{
    if(_c.getBleu()>255) _c.setBleu(255);
    if(_c.getRouge()>255) _c.setRouge(255);
    if(_c.getVert()>255) _c.setVert(255);
    std::cout<<"Constructeur de figure\n";
}

figure::figure(unsigned short int rouge, unsigned short int bleu,unsigned short int vert,int x, int y)
    :_c(rouge,bleu,vert),_p(x,y)
{
    if(_c.getBleu()>255) _c.setBleu(255);
    if(_c.getRouge()>255) _c.setRouge(255);
    if(_c.getVert()>255) _c.setVert(255);
    std::cout<<"Constructeur de figure avec param point d'origine\n";
}

void figure::affichage() const {
    std::cout<<"Point d'origine ";
    _p.afficherPoint();
    std::cout<<"Couleur RGB : "<< _c.getRouge()<<_c.getBleu()<<_c.getVert();
}

point const & figure::getP() const{
    return _p;
}

bool figure::memeOrigine(figure const & F) const{
    return F.getP().getX() == this->getP().getX() && F.getP().getY() == F.getP().getY();
}

void figure::translation(point const & P) {
    _p.translation(P);
}


