#include <iostream>
#include "pointeurintelligent.h"

using namespace std;

int main()
{
    auto psp = produitperissable::fabriqueSharedPtr("1/1/1","miam",10);
    auto pup = produitperissable::fabriqueUniquePtr("2/2/2","miam+",5);
    stock S;
    // ajout shared
    S.ajouter(psp);
    // ajout unique
    S.ajouter(std::move(pup));
    stock S2;
    S2.ajouter(psp);
    S2 = S;
    std::cout<<S2;
    S2.utilisationDynamicCast();
    return 0;
}
