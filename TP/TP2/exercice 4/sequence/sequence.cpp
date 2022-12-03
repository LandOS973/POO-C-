#include "sequence.h"
#include <iostream>

sequence::sequence(): _taille(0){}

sequence::sequence(const sequence & S)
{
    for (std::vector<int>::size_type i(0); i<S._couleurs.size(); ++i){
        _couleurs.push_back(S._couleurs[i]);
        _taille++;
    }
}

const couleur & sequence::acces(int i) const {
    return _couleurs.at(i);
}

const indicesequence & sequence::getTaille() const{
    return _taille;
}

void sequence::ajouter(const couleur & c) {
    _couleurs.push_back(c);
    _taille++;
}

void sequence::afficher(std::ostream & out) const {
    for(indicesequence i = 0; i < _couleurs.size(); i++) {
        switch (_couleurs.at(i))
        {
        case couleur::rouge:
            out << "rouge ";
            break;
        case couleur::jaune:
            out << "jaune ";
            break;
        case couleur::vert:
            out << "vert ";
            break;
        case couleur::bleu:
            out << "bleu ";
            break;
        default:
            break;
        }
    }
    out<<"\n";
}

void sequence::afficher(couleur c) const {
    switch (c)
    {
    case couleur::rouge:
        std::cout << "rouge ";
        break;
    case couleur::jaune:
        std::cout << "jaune ";
        break;
    case couleur::vert:
        std::cout << "vert ";
        break;
    case couleur::bleu:
        std::cout << "bleu ";
        break;
    default:
        break;
    }
}

bool sequence::comparer(const sequence & S) const {
    if(S.getTaille() != getTaille())
        return false;
    for (std::vector<int>::size_type i(0); i<S._couleurs.size(); ++i){
        if(_couleurs.at(i) != S._couleurs[i])
            return false;
    }

    return true;
}

void sequence::vider(){
    _couleurs.clear();
}

void sequence::copier(const sequence & S){
    vider();
    _taille = S._taille;
    for (std::vector<int>::size_type i(0); i<S._couleurs.size(); ++i){
        _couleurs.push_back(S._couleurs[i]);
    }
}



