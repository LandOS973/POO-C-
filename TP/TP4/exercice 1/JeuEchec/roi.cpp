#include "roi.h"

roi::roi(const couleur &C, const position &P) : piece(C, P){}

char roi::name() const
{
    return 'R';
}

std::unique_ptr<piece> roi::clone() const
{
    return std::make_unique<roi>(*this);
}

unsigned short roi::valeur() const
{
    return 20;
}

void roi::deplacementPossibles()
{
    viderDeplacement();
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if(position(P().horizontal()+i,P().vertical()+j).estValide() && (position(P().horizontal()+i,P().vertical()+j)) != P()){
                ajouterDeplacement(position(P().horizontal()+i,P().vertical()+j));
            }
        }
    }
}
