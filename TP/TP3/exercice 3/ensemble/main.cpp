#include <iostream>
#include "ensemblevector.h"
#include "ensembletableau.h"
#include "parcours.h"

using namespace std;

int main()
{
    ensembleVector V1;
    ensembleTableau V2;
    V1.ajout(4);
    V1.ajout(5);
    V2.ajout(1);
    V2.ajout(2);
    V2.unionE(V1,V2);
    V1.afficher();
    return 0;
}
