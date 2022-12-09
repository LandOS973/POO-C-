#include "tableau.h"

// ################### ARRAYINT ##########################

arrayint::arrayint(int indicemin, int indicemax) : _indicemin(indicemin),
    _indicemax(indicemax), _elements(indicemax - indicemin+1)
{}

int arrayint::indicemin() const
{
    return _indicemin;
}

int arrayint::indicemax() const
{
    return _indicemax;
}

int arrayint::at(int indice) const
{
    if(indice < indicemin() || indice >= indicemax()) throw exceptionarrayint(indice, "error method at()! a l'indice : " + std::to_string(indice));
    else return _elements[indice - indicemin()];
}

void arrayint::set(int val, int i)
{
    if(i < indicemin() || i >= indicemax()) throw exceptionarrayint(i,"indice error method set()!");
    else _elements[i - indicemin()] = val;
}

int &arrayint::operator[](int i)
{
    if(i < indicemin() || i >= indicemax()) throw exceptionarrayint(i,"indice error method operator[]!");
    else return _elements[i - indicemin()];
}

bool arrayint::operator==(const arrayint &p) const
{
    if(_elements.size() != p._elements.size()) return false;
    for(int i = p.indicemin() ; i < p.indicemax() ; i++){
       if(_elements[i] != p._elements[i]) return false;
    }
    return true;
}


std::ostream & operator<<(std::ostream &os,arrayint const &S){
    for(int i = S.indicemin() ; i < S.indicemax() ; i++){
        os<<S.at(i);
    }
    return os;
}

arrayint &arrayint::operator=(const arrayint &s)
{
    if(this != &s){
        _elements.clear();
        for(auto const &p : s._elements){
            _elements.push_back(p); // clone
        }
    }
    return *this;
}

//#################### EXCEPTION ##########################

exceptionarrayint::exceptionarrayint(int indice, const std::string &msg) : std::exception(),
    _indice(indice),
    _msg(msg)
{}

const char *exceptionarrayint::what() const noexcept
{
    return _msg.c_str();
}

