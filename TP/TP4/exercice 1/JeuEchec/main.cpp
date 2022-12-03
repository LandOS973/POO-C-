#include <iostream>
#include "echequier.h"
#include <fstream>

using namespace std;

int main()
{
    // position(A,4)
    echequier E;
    E.deplacer(position(2,1),position(3,3));
    echequier E2=E;
    E2.afficherNoir(std::cout);
    std::ofstream ofs ("test.txt");
    E2.sauvegarde(ofs);
}
