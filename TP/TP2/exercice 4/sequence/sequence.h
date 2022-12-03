#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <string>
#include <vector>
#include <iostream>
using indicesequence = size_t;

enum class couleur
{
    rouge,
    jaune,
    bleu,
    vert
};

class sequence
{
private:
    std::vector<couleur> _couleurs;
    indicesequence _taille;
public:
    sequence();
    sequence(const sequence & S);
    const couleur & acces(int i) const;
    void ajouter(const couleur & c);
    void afficher(std::ostream  & O) const;
    void afficher(couleur c) const;
    bool comparer(const sequence & S) const;
    const indicesequence & getTaille() const;
    couleur *const & getCouleurs() const;
    void copier(const sequence & S);
    void vider();
};

#endif // SEQUENCE_H
