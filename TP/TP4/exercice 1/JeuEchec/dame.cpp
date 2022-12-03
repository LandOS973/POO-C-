#include "dame.h"

dame::dame(const couleur &C, const position &P) : piece(C, P){}

char dame::name() const
{
    return 'D';
}

std::unique_ptr<piece> dame::clone() const
{
    return std::make_unique<dame>(*this);
}

unsigned short dame::valeur() const
{
    return 9;
}

void dame::deplacementPossibles()
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
    for (int k = 0; k < 4; k++) {
        while (position(P().horizontal()+i,P().vertical()+j).estValide()) {
            if(position(P().horizontal()+i,P().vertical()+j) != P())ajouterDeplacement(position(P().horizontal()+i,P().vertical()+j));
            switch (k) {
            case 0: j++; break;
            case 1: j--; break;
            case 2: i++; break;
            case 3: i--; break;
            default: break;
            }
        }
        j = 0;
        i = 0;
    }
    for (auto i : getDeplacement()) {
        std::cout<<i;
    }
}
