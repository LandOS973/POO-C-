#include "sequence.h"
#include <iostream>

sequence::sequence() : _taille(0), _couleurs(nullptr){}

sequence::~sequence()
{
    delete[] _couleurs;
}

sequence::sequence(const sequence & S) : _taille(S.getTaille()), _couleurs(nullptr)
{
    if(S.getTaille() > 0)
        _couleurs = new couleur[S.getTaille()];
        for (indicesequence i = 0; i < S.getTaille(); ++i)
            _couleurs[i] = S.acces(i);
}


const indicesequence & sequence::getTaille() const {
    return _taille;
}

const couleur & sequence::acces(int i) const {
    return _couleurs[i];
}

void sequence::ajouter(const couleur & c) {
    couleur * nouveau(new couleur[_taille + 1]);
    nouveau[_taille] = c;
    for (int i = 0; i < _taille; ++i) {
        nouveau[i] = _couleurs[i];
    }
    delete [] _couleurs;
    _couleurs = nouveau;
    _taille++;
}

void sequence::afficher(std::ostream & out) const {
    for(indicesequence i = 0; i < this->getTaille(); i++) {
        switch (_couleurs[i])
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

void sequence::afficher(couleur const & c) {
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
    if(S._taille != _taille)
        return false;
    for(indicesequence i = 0; i < _taille; i++)
        if(acces(i) != S.acces(i))
            return false;
    return true;
}

void sequence::copier(const sequence & S){
    if(_taille != S.getTaille()){
        delete[] _couleurs;
        _couleurs = (S.getTaille() == 0) ? nullptr: new couleur[S.getTaille()];
        _taille = S.getTaille();
    }
    for (indicesequence i = 0; i < S.getTaille(); ++i) {
        _couleurs[i] = S.acces(i);
    }
}

void sequence::vider(){
    delete [] _couleurs;
    _couleurs = nullptr;
    _taille = 0;

}

