#include "texte.h"
#include <iostream>

texte::texte(unsigned short int rouge, unsigned short int bleu,unsigned short int vert, std::string const & txt)
    :figure(rouge,bleu,vert), _t(txt)
{
    std::cout<<"Constructeur de texte \n";
}

texte::texte(unsigned short int rouge, unsigned short int bleu,unsigned short int vert,int x, int y, std::string const & txt)
    :figure(rouge,bleu,vert,x,y), _t(txt)
{
    std::cout<<"Constructeur de texte avec initialisation de point \n";
}

void texte::affichage() const {
    std::cout<<"Type de figure : texte { \n    ";
    figure::affichage();
    std::cout<<" Texte : " <<_t;
    std::cout<<"\n}\n";
}
