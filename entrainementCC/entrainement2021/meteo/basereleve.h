#ifndef BASERELEVE_H
#define BASERELEVE_H
#include "releve.h"
#include "temperature.h"
#include "vent.h"
#include "precipitation.h"
#include <iostream>
#include <vector>
#include <list>

class basereleve
{
private:
    std::list<temperature>_temperatures;
    std::list<vent>_vents;
    std::list<precipitation>_precipitations;
public:
    basereleve();
    bool ajout(const temperature &t);
    bool ajout(const vent &v);
    bool ajout(const precipitation &p);
    /*Écrire une méthode sortirrecents prenant comme argument un flux de sortie et une datereleve
et sortant sur le flux les relevés postérieurs à la datereleve passée.*/
    void sortirrecents(std::ostream &os,const datereleve &d);
    /*Écrire une méthode tempmoyenne prenant comme argument une datereleve et retournant la
température moyenne relevée à cette date-là (par date, on entend jour et mois), en prenant en
compte tous les relevés de température de cette date (l’heure de la datereleve passée en argument
sera donc ignorée).*/
    float tempmoyenne(const datereleve &d);
    /*. Écrire une méthode tempsdangereux retournant les datereleve pour lesquels il y a un relevé de
vent, une température inférieure à 2, et des précipitations de neige ou grêle.*/
    const std::vector<datereleve> & tempsdangereux();
};

#endif // BASERELEVE_H
