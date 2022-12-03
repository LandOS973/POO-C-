#ifndef HORAIRE_H
#define HORAIRE_H
#include <string>
using date = unsigned int;

class horaire
{
private:
    date mois;
    date jour;
    date heure;
public:
    horaire(date mois, date jour, date heure);
    std::string tostring() const;
    date getMois() const;
    date getJour() const;
    date getHeure() const;
};

#endif // HORAIRE_H
