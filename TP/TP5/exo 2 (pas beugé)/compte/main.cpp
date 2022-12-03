#include <iostream>
#include "proprietaire.h"

using namespace std;

int main()
{
    auto p1=proprietaire::fabrique("aa","Angers","12/12/2022");
    auto p2=proprietaire::fabrique("efaa","Angers","02/02/2022");
    auto s=proprietaire::fabrique("ff","jjus",p1);
    auto c=proprietaire::fabrique(p1,p2);
    auto l = LEP::fabrique(p1,880);
    banque B;
    B.ajouter(l);
    std::cout<<*B.chercheproprietaire("aa");
}
