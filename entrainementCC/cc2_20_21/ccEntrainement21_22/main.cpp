#include <iostream>
#include "projetetudiant.h"
#include <QApplication>

using namespace std;

int main(int argc,char ** argv)
{
    std::vector<languages> L;
    L.push_back(languages::cpp);
    L.push_back(languages::js);
    L.push_back(languages::python);
    auto M1 = etudiantM1::fabrique(L,"thomas");

    universite U;
    U.ajout(M1);
    U.ajout(etudiantM2::fabrique(5,"yo"));
    std::cout<<U;
    return 0;
}
