#ifndef HORAIRE_H
#define HORAIRE_H
#include <string>

class horaire
{
private:
    unsigned int _mois;
    unsigned int _jour;
    unsigned int _heure;
public:
    horaire(unsigned int mois,unsigned int jour,unsigned int heure);
    horaire();
    unsigned int mois() const;
    unsigned int jour() const;
    unsigned int heure() const;
    std::string tostring() const;
};

#endif // HORAIRE_H
