#include "sequence.h"

void sc_initialiservide(sequence & S){
    S.taille = 0;
    S.couleurs = nullptr;
}


void sc_ajouter(sequence & S, couleur c){
    couleur * nouveau(new couleur[S.taille + 1]);
    nouveau[S.taille] = c;
    for (int i = 0; i < S.taille; ++i) {
        nouveau[i] = S.couleurs[i];
    }
    delete [] S.couleurs;
    S.couleurs = nouveau;
    S.taille++;
}

void sc_copier(sequence & destination, sequence const & source){
    if(source.taille != destination.taille){
        delete[] destination.couleurs;
        destination.couleurs = (source.taille == 0) ? nullptr: new couleur[source.taille];
        destination.taille = source.taille;
    }
    for (indicesequence i = 0; i < source.taille; ++i) {
        destination.couleurs[i] = source.couleurs[i];
    }
}

couleur acces(sequence S,indicesequence i){
    return S.couleurs[i];
}

void sc_afficher(couleur c){
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

void sc_vider(sequence & S){
    delete [] S.couleurs;
    S.couleurs = nullptr;
    S.taille = 0;
}

void sc_afficher(const sequence &s)
{
    for (indicesequence i = 0; i < s.taille; ++i)
    {
        sc_afficher(acces(s, i));
    }
    std::cout << "\n";
}

bool sc_comparer(const sequence &a, const sequence &b)
{
    if (a.taille != b.taille)
        return false;
    for (indicesequence i = 0; i < a.taille; i++)
        if (a.couleurs[i] != b.couleurs[i])
            return false;
    return true;
}
