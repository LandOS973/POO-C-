#include <iostream>
#include "cc.h"

using namespace std;

int main()
{
    auto E = espace::fabrique("Espace de cours de thomas très interessant");
    auto E2 = espace::fabrique("E");
    auto P = std::make_unique<fichier>("url");
    auto P2 = page::fabrique(5);
    P2->ajouterSection(section{"contenu",false});
    devoir D(std::make_shared<fichier>("url2"));
    D.ajouterRendu(rendu{"a","b"});
    E->ajouterelement(D.clone());
    E->ajouterelement(P2->clone());
    E->ajouterelement(devoir(nullptr).clone());
    E->ajouterelement(std::move(P));
    E2 = E;
    std::cout<<*E2;
    return 0;
}
