#include <iostream>
#include "element.h"
#include "personnage.h"
using namespace std;

int main()
{
    personnage P(1,2,3,4,"Thomas");
    objetramassable O(1,2,3,4,23);
    P.ramasserObjet(O);
    std::cout<<P.toString();
    return 0;
}
