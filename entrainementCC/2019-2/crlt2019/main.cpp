#include <iostream>
#include "basemessages.h"
using namespace std;

int main()
{
    std::list<horaire>L;
    std::vector<std::string>D;
    D.push_back("h");
    L.push_back(horaire(1,1,1));
    basemessages B;
    proposition p("yo",L,"arthur",D);
    B.ajout(p);
    B.afficher();
    B.repondre(p,"blabla",horaire(1,2,3));
    B.afficher();

    return 0;
}
