#include "cavalier.h"


cavalier::cavalier(const couleur &C, const position &P) : piece(C, P){}

void cavalier::deplacementPossibles()
{
    viderDeplacement();
    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            if(i!=j && position(P().horizontal()+i,P().vertical()+j).estValide() && i != 0 && j!= 0 && i!=-j && j!=-i){
                ajouterDeplacement(position(P().horizontal()+i,P().vertical()+j));
            }
        }
    }
}

char cavalier::name() const
{
    return 'C';
}

std::unique_ptr<piece> cavalier::clone() const
{
    return std::make_unique<cavalier>(*this);
}

unsigned short cavalier::valeur() const
{
    return 3;
}
