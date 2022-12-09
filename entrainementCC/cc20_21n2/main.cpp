#include <iostream>
#include <QApplication>
#include "cc.h"
using namespace std;

int main(int argc,char ** argv)
{
    auto M = M1::fabrique({langages::js,langages::python},"thomas");
    auto M2 = M2::fabrique(5,"toto");
    std::cout<<*M;
    unversite U;
    U.ajouter(M);
    U.ajouter(M2);
    std::cout<<U.rechercherdevs(langages::cpp).size();
    projet P;
    P.ajouter(M);
    P.ajouter(M2);
    QApplication app(argc,argv);
    app.setStyleSheet("background-color: black;");
    saisi C(U);
    C.show();
    return app.exec();

    return 0;
}
