#include "piece.h"

const couleur &piece::getColor() const
{
    return _C;
}

const position &piece::P() const
{
    return _P;
}

void piece::setP(const position &newP)
{
    _P = newP;
}

void piece::ajouterDeplacement(const position &p)
{
    deplacement.push_back(p);
}

void piece::viderDeplacement()
{
    deplacement.clear();
}


const std::vector<position> &piece::getDeplacement() const
{
    return deplacement;
}

piece::piece(couleur const & c, position const & p): _C(c),_P(p){}

std::string piece::toString() const
{
    std::string s = std::string(1,name());
    _C == couleur::NOIR ? s += "B" : s += "N";
    s += char(_P.horizontal() + 64) + std::to_string(_P.vertical());
    return s;
}

bool piece::deplacer(position const & P){
    deplacementPossibles();
    for (auto i : deplacement) {
        if(P == i){
            _P.setHorizontal(P.horizontal());
            _P.setVertical(P.vertical());
            return true;
        }
    }
    return false;
}
