#include "fou.h"

fou::fou(const couleur &C, const position &P) : piece(C, P){}

void fou::deplacementPossibles()
{
    viderDeplacement();
    int j = 0;
    int i = 0;
    for (int k = 0; k < 4; k++) {
        while (position(P().horizontal()+i,P().vertical()+j).estValide()) {
            if(position(P().horizontal()+i,P().vertical()+j) != P())ajouterDeplacement(position(P().horizontal()+i,P().vertical()+j));
            switch (k) {
            case 0:
                j++;
                i++;
                break;
            case 1:
                j--;
                i++;
                break;
            case 2:
                j++;
                i--;
                break;
            case 3:
                j--;
                i--;
                break;
            default:
                break;
            }

        }
        j = 0;
        i = 0;
    }
}

char fou::name() const
{
    return 'F';
}

std::unique_ptr<piece> fou::clone() const
{
    return std::make_unique<fou>(*this);
}

unsigned short fou::valeur() const
{
    return 3;
}
