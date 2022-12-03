#include <iostream>
#include "texte.h"
#include "proposition.h"
#include "basemessage.h"
#include <list>
using namespace std;

int main()
{
    std::vector<std::string>destinataire;
    destinataire.push_back("Y");
    destinataire.push_back("Z");
    std::list<horaire>HS;
    horaire H(1,1,1);
    HS.push_back(H);
    HS.push_back(horaire(111,1,1));
    auto T = std::make_unique<proposition>(HS,"reu","X",destinataire);
    basemessage B;
    B.ajoutMessage(std::move(T));
    auto T2 = std::make_unique<texte>("blabla","Y",destinataire);
    B.ajoutMessage(std::move(T2));
    B.ajoutMessage(std::move(std::make_unique<texte>("blabla","Y",destinataire)));
    B.repondre(proposition(HS,"reu","X",destinataire),"Y",horaire(1,1,1));
    B.affichemessage();
    return 0;
}
