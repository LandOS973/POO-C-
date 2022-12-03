#ifndef DATERELEVE_H
#define DATERELEVE_H
#include <string>

using date = unsigned int;

class datereleve
{
private:
    date _mois;
    date _jour;
    date _heure;
    date _annee;

public:
    datereleve(date mois, date jour, date heure, date annee);
    std::string tostring() const;
    /*Munir cette classe d’une méthode comparememejour déterminant si deux datereleve concernent le
    même jour du même mois de la même année, ainsi qu’une méthode compareavant déterminant si
    une datereleve se situe avant une autre datereleve dans l’ordre chronologique.*/
    static bool comparememejour(const datereleve &D1,const datereleve &D2);
    static bool compareavant(const datereleve &D1,const datereleve &D2);
    bool operator==(const datereleve &D) const;

};

#endif // DATERELEVE_H
