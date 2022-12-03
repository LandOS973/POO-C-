#include "ensemblevector.h"

void ensembleVector::setEntiers(const std::vector<int> &newEntiers)
{
    _entiers = newEntiers;
}

ensembleVector::ensembleVector(){}

ensembleVector::ensembleVector(ensembleVector const &E)
{
    _entiers = E._entiers;
}

void ensembleVector::ajoutSansVerif(int x){
    _entiers.push_back(x);
}

void ensembleVector::afficher() const {
    std::cout<<"{";
    for (auto i : _entiers) {
        std::cout<<i;
        if(i != _entiers[_entiers.size() - 1]) std::cout<<", ";
    }
    std::cout<<"}";
}

bool ensembleVector::vide() const {
    return _entiers.empty();
}

bool ensembleVector::appartient(int x) const {
    for (auto i : _entiers) {
        if(x == i) return true;
    }
    return false;
}

void ensembleVector::enlever(int x){
    for (int i = 0; i < _entiers.size(); ++i) {
        if(_entiers[i] == x) _entiers.erase(_entiers.begin() + i);
        return;
    }
}

std::vector<int> const & ensembleVector::getEntiers() const {
    return _entiers;
}

int ensembleVector::estFini() const{
    return _entiers.size();
}
