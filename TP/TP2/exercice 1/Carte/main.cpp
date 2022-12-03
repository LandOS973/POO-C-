#include <iostream>
#include <string>
using namespace std;
#include "tailleposition.h"

int main()
{
    position P(1,2);
    position P2(P);
    P.set_x(3);
    std::cout<<P.comparaison(P2);
    taille T(3,4);
    std::cout<<T.get_hauteur();
    return 0;
}
