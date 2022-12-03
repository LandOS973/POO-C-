#include <iostream>
#include "file.h"
#include <QApplication>

using namespace std;

int main(int argc,char ** argv)
{
    QApplication app(argc,argv);
    app.setStyleSheet("background-color: black;");
    maClass C;
    C.show();
    return app.exec();
    return 0;
}
