#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <string>
#include <array>
#include <iostream>
using indicesequence = std::size_t;

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
    couleur * _couleurs;
    indicesequence _taille;
public:
    sequence();
    sequence(const sequence & S);
    ~sequence();
    const couleur & acces(int i) const;
    void ajouter(const couleur & c);
    void afficher(std::ostream  & O) const;
    static void afficher(couleur const & c);
    bool comparer(const sequence & S) const;
    const indicesequence & getTaille() const;
    couleur *const & getCouleurs() const;
    void copier(const sequence & S);
    void vider();
};

#endif // SEQUENCE_H
