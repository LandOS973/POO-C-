#include "sequence.h"
#include <iostream>

int main() {
    sequence a;
    a.ajouter(couleur::rouge);
    a.ajouter(couleur::bleu);
    a.ajouter(couleur::rouge);
    a.ajouter(couleur::vert);
    sequence::afficher(a.acces(0)); std::cout << "\n";
    sequence b(a);
    for (indicesequence i=0; i<a.getTaille(); ++i)
        sequence::afficher(a.acces(i));
    std::cout << "\n";
    a.vider();
    std::cout << "A: "; a.afficher(std::cout);
    std::cout << "B: "; b.afficher(std::cout);
    std::cout << a.comparer(b) << "\n";
    a.copier(b);
    std::cout << a.comparer(b) << "\n";
    return 0;
}
