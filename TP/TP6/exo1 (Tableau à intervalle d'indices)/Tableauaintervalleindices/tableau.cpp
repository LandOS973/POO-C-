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
    if(indice < indicemin() || indice >= indicemax()) throw exceptionarrayint(indice,"indice error method at()!");
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

//#################### EXCEPTION ##########################

exceptionarrayint::exceptionarrayint(int indice, const std::string &msg) : std::exception(),
    _indice(indice),
    _msg(msg)
{}

const char *exceptionarrayint::what() const noexcept
{
    return _msg.c_str();
}

