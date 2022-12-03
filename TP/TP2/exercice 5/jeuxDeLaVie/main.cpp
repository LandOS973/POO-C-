#include <iostream>
#include "grille.h"
#include <stdlib.h>

using namespace std;
// faire tourner le programme dans un terminal externe
int main()
{
    std::cout<<"           ==== JEUX DE LA VIE ==== \n";
    grille G(40,40);
    G.ajouterStructure(symbole::planeur,2,2);
    G.ajouterStructure(symbole::floraison,5,5);
    G.ajouterStructure(symbole::oscillateur,12,14);
    G.ajouterStructure(symbole::oscillateurligne,15,25);
    G.voirEvolution(G);
    return 0;
}
