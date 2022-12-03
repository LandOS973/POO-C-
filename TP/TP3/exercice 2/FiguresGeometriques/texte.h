#ifndef TEXTE_H
#define TEXTE_H
#include "figure.h"

class texte: public figure {
private:
    std::string _t;
public:
    texte(unsigned short int rouge, unsigned short int bleu,unsigned short int vert, std::string const & txt);
    texte(unsigned short int rouge, unsigned short int bleu,unsigned short int vert,int x, int y, std::string const & txt);
    void affichage() const override;
};

#endif // TEXTE_H
