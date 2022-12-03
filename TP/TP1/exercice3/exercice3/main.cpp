#include "sequence.h"
#include <iostream>

int main()
{
    sequence a, b;
    sc_initialiservide(a);
    sc_initialiservide(b);
    sc_ajouter(a, couleur::rouge);
    sc_ajouter(a, couleur::bleu);
    sc_ajouter(a, couleur::rouge);
    sc_ajouter(a, couleur::vert);
    sc_copier(b, a);
    sc_afficher(acces(a, 0));
    std::cout << "\n";
    for (indicesequence i = 0; i < a.taille; ++i)
        sc_afficher(acces(a, i));
    sc_vider(a);
    std::cout << std::endl;
    std::cout << "A: ";
    sc_afficher(a);
    std::cout << "B: ";
    sc_afficher(b);
    std::cout << sc_comparer(a, b) << "\n";
    sc_copier(a, b);
    std::cout << sc_comparer(a, b) << "\n";
    return 0;
}
