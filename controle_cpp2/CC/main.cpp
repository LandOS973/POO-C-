#include <iostream>
#include <QApplication>
#include "cc.h"


using namespace std;

int main(int argc,char ** argv)
{
    QApplication app(argc,argv);
    app.setStyleSheet("background-color: black;");
    auto v = vacances::fabrique(horaire(1,1,1),70);
    std::cout<<*v;
    auto e = creneauxens::fabrique(unite::POO,horaire(9,9,9));
    std::cout<<*e;
    carnet C2;
    C2.ajouter(v);
    C2.ajouter(e);
    //C2.ajouter(e); => declache une exception
    qt_decaler C(v);
    C.show();
    return app.exec();
}
