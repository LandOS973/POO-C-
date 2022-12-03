#ifndef SEQUENCE_H
#define SEQUENCE_H
#pragma once
#include <array>
#include <iostream>
const int TMAX = 100;
using indicesequence = unsigned int;

enum class couleur
{
    rouge,
    jaune,
    bleu,
    vert
};

struct sequence
{
    std::array<couleur, TMAX> couleurs;
    indicesequence n;
};

void sc_initialiservide(sequence &S)
{
    S.n = 0;
}

void sc_ajouter(sequence &S, const couleur &C)
{
    S.couleurs[S.n] = C;
    S.n++;
}

void sc_afficher(const couleur & c)
{
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

void sc_copier(sequence &b, const sequence &a)
{
    b.n = a.n;
    for (unsigned int i = 0; i < a.n; i++)
    {
        b.couleurs[i] = a.couleurs[i];
    }
}

couleur sc_acces(const sequence &s, int x)
{
    return s.couleurs[x];
}

void sc_vider(sequence &s)
{
    s.n = 0;
}

void sc_afficherTout(const sequence &s)
{
    for (indicesequence i = 0; i < s.n; ++i)
    {
        sc_afficher(sc_acces(s, i));
    }
    std::cout << "\n";
}

bool sc_comparer(const sequence &a, const sequence &b)
{
    if (a.n != b.n)
        return false;
    for (indicesequence i = 0; i < a.n; i++)
        if (a.couleurs[i] != b.couleurs[i])
            return false;
    return true;
}

#endif // SEQUENCE_H
