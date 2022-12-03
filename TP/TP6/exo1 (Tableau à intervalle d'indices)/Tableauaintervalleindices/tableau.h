#include <vector>
#include <string>
#include <iostream>

#pragma once

// ################### ARRAYINT ###########################

/* Écrire une méthode set prenant comme paramètre un indice et une valeur et modifiant la valeur
mémorisée dans le tableau pour l’indice passé*/

class arrayint{
public:
    arrayint(const arrayint & A) = default;
    arrayint(int indicemin, int indicemax);
    int indicemin() const;
    int indicemax() const;
    int at(int indice) const;
    void set(int val,int i);
    int &operator[](int i);
private:
    int _indicemin;
    int _indicemax;
    std::vector<int> _elements;

};

//#################### EXCEPTION ##########################

class exceptionarrayint : public std::exception {
private:
    int _indice;
    std::string _msg;
    // exception interface
public:
    exceptionarrayint(int indice, const std::string &msg);
    const char *what() const noexcept override;
};
