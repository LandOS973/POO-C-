#include <iostream>
#include "jeu.h"


using namespace std;

int main()
{
    jeu J;
    J.ajouter(invader(4,4,direction::stop,position(4,4)));
    J.tirjoueur();
    J.tourdejeu();
    J.afficherjeu();
    return 0;
}
