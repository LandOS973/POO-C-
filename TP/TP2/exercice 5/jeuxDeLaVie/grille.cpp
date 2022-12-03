#include "grille.h"
#include <vector>


grille::grille(size_t hauteur, size_t largeur):_hauteur(hauteur), _largeur(largeur)
{
    _matrice.resize(_hauteur);
    for (int i = 0; i < _hauteur; ++i) {
        _matrice.at(i).resize(_largeur);
    }
    for (int i = 0; i < _hauteur; ++i) {
        for (int j = 0; j < _largeur; ++j) {
            _matrice[i][j] = etatcellule::morte;
        }
    }
}

void grille::afficher() const{
    std::string s;
    for (int i = 0; i <= _largeur; ++i) {
        s+= " _ ";
    }
    s+="press enter to continue...";
    for (int i = 0; i < _hauteur; ++i) {
        for (int j = 0; j < _largeur; ++j) {
             _matrice[i][j] == etatcellule::morte ? std::cout<<"   " : std::cout<<" * ";
        }
        std::cout<<std::endl;
    }
    std::cout<<s;
}

void grille::vider(){
    for (int i = 0; i < _hauteur; ++i) {
        for (int j = 0; j < _largeur; ++j) {
            _matrice[i][j] = etatcellule::morte;
        }
    }
}

bool grille::vivante(int x, int y) const {
    if(x >= _hauteur || y >= _largeur) return false;
    return _matrice[x][y] == etatcellule::vivante;
}
void grille::generer(int x, int y) {
    _matrice[x][y] = etatcellule::vivante;
}

void grille::tuer(int x, int y) {
    _matrice[x][y] = etatcellule::morte;
}

void grille::ajouterStructure(symbole const & S, int x, int y){
    switch (S) {
    case symbole::oscillateurligne:
        grille::generer(x,y);
        grille::generer(x,y+1);
        grille::generer(x,y+2);
        break;
    case symbole::planeur:
        grille::generer(x,y);
        grille::generer(x,y+1);
        grille::generer(x,y+2);
        grille::generer(x+1,y+2);
        grille::generer(x+2,y+1);
        break;
    case symbole::oscillateur:
        grille::generer(x,y+1);
        grille::generer(x+1,y+1);
        grille::generer(x+1,y);
        grille::generer(x+1,y+2);
        grille::generer(x+2,y+1);
        break;
    case symbole::floraison:
        grille::generer(x,y+1);
        grille::generer(x,y+2);
        grille::generer(x,y+3);
        grille::generer(x+1,y);
        grille::generer(x+1,y+2);
        grille::generer(x+1,y+4);
        grille::generer(x+2,y+1);
        grille::generer(x+2,y+2);
        grille::generer(x+2,y+3);
        break;
    default:
        break;
    }
}

signed int grille::vivantes(signed int x, signed int y) const {
    int nbr = 0;
    vivante(x-1,y) ? nbr ++ : 0;
    vivante(x-1,y-1) ? nbr ++ : 0;
    vivante(x,y-1)? nbr ++ : 0;
    vivante(x+1,y-1) ? nbr ++ : 0;
    vivante(x+1,y) ? nbr ++ : 0;
    vivante(x-1,y+1)? nbr ++ : 0;
    vivante(x,y+1) ? nbr ++ : 0;
    vivante(x+1,y+1) ? nbr ++ : 0;
    return nbr;
}
void grille::evolution(grille const & G){
    for (int i = 0; i < _hauteur; ++i) {
        for (int j = 0; j < _largeur; ++j) {
            if(G.vivantes(i,j) <= 1 || G.vivantes(i,j) >= 4)
                tuer(i,j);
            if(G.vivantes(i,j) == 3)
                generer(i,j);
        }
    }
}

void grille::voirEvolution(grille const & G){
    std::string s;
    afficher();
    std::getline(std::cin, s);
    while (s == "") {
        evolution(G);
        afficher();
        std::getline(std::cin, s);
    }
}

