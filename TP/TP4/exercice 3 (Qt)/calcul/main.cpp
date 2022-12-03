#include <iostream>
#include "calcul.h"
#include <QApplication>

using namespace std;

int main(int argc,char ** argv)
{
    QApplication app(argc,argv);
    app.setStyleSheet("background-color: black;");
    calcul C;
    C.show();
    return app.exec();
}
