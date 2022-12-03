#include "ensembletableau.h"

ensembleTableau::ensembleTableau(): _taille(0), _entiers(nullptr){}

ensembleTableau::~ensembleTableau(){
    delete [] _entiers;
}

ensembleTableau::ensembleTableau(ensembleTableau const & E): _taille(E._taille), _entiers(nullptr)
{
    if(E._taille > 0){
        _entiers = new int[_taille];
        for (int i = 0; i < _taille; ++i) {
            _entiers[i] = E._entiers[i];
        }
    }
}

void ensembleTableau::ajoutSansVerif(int x){
    int * nouveau(new int[_taille + 1]);
    nouveau[_taille] = x;
    for (int i = 0; i < _taille; ++i) {
        nouveau[i] = _entiers[i];
    }
    delete [] _entiers;
    _entiers = nouveau;
    _taille++;
}

void ensembleTableau::afficher() const {
    std::cout<<"{";
    for (int i = 0; i < _taille; ++i) {
        std::cout<<_entiers[i];
        if(i != _taille-1) std::cout<<", ";
    }
    std::cout<<"}";
}

bool ensembleTableau::vide() const {
    return _taille == 0;
}

bool ensembleTableau::appartient(int x) const {
    for (int i = 0; i < _taille; ++i) {
        if(x == _entiers[i]) return true;
    }
    return false;
}

void ensembleTableau::enlever(int x){
    for (size_t i = 0; i < _taille; ++i) {
        if(_entiers[i] == x){
            if(_taille == 1){
                delete[] _entiers;
            }else{
                _entiers[i] = _entiers[_taille - 1];
            }
            _taille--;
            return;
        }
    }
}

int * const & ensembleTableau::getEntiers() const {
    return _entiers;
}

int ensembleTableau::estFini() const {
    return _taille;
}

void ensembleTableau::vider() {
    delete[] _entiers;
    _taille = 0;
}

int ensembleTableau::acces(int x) const {
    return _entiers[x];
}
