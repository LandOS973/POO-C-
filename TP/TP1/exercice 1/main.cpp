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
    sc_afficher(sc_acces(a, 0));
    std::cout << "\n";
    for (indicesequence i = 0; i < a.n; ++i)
        sc_afficher(sc_acces(a, i));
    sc_vider(a);
    std::cout << std::endl;
    std::cout << "A: ";
    sc_afficherTout(a);
    std::cout << "B: ";
    sc_afficherTout(b);
    std::cout << sc_comparer(a, b) << "\n";
    sc_copier(a, b);
    std::cout << sc_comparer(a, b) << "\n";
    return 0;
}
