#include <iostream>
#include "carte.h"
using namespace std;

int main()
{
    carte C(100,100);
    objetramassable O1(30,30,30,30,50);
    personnage P(2,2,2,2,"Thomas");
    C.ajout(O1);
    C.ajout(P);
    C.deplacer(P,30,30);
    C.ramasserObj(P);
    C.afficher();
    return 0;
}
