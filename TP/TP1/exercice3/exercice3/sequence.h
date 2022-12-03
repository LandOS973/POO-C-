#pragma once
#include <iostream>

using indicesequence = std::size_t;

enum class couleur
{
    rouge,
    jaune,
    bleu,
    vert
};

struct sequence {
    couleur * couleurs;
    indicesequence taille;
};

void sc_initialiservide(sequence & s);
void sc_ajouter(sequence & s, couleur c);
void sc_copier(sequence & destination, sequence const & source);
void sc_copier(sequence & destination, sequence const & source);
couleur acces(sequence S,indicesequence i);
void sc_afficher(couleur c);
void sc_vider(sequence & S);
void sc_afficher(const sequence &s);
bool sc_comparer(const sequence &a, const sequence &b);
