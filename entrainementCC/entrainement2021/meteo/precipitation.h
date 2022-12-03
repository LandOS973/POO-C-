#ifndef PRECIPITATION_H
#define PRECIPITATION_H
#include "releve.h"

/*Nous allons maintenant décrire les relevés. Chaque relevé a été effectué à une datereleve. Il y a trois
types de relevés :
temp pour un relevé de température exprimée en dixièmes de degrés celsius (int, par exemple 201
pour 20.1°C) ;
prec pour un relevé de précipitations pour lequel on mémorisera le type de précipitations (pluie,
grêle ou neige) ainsi que la quantité mesurée en millimètres (int) ;
vent pour la direction du vent (Nord, Sud, Est, Ouest).
Déclarer les classes pour représenter les relevés et écrire les constructeurs. Il n’y aura pas de
mutateurs : les valeurs des attributs seront fixées à la construction et ne seront pas modifiées ensuite.*/

enum class type{
    pluie,grele,neige
};

class precipitation : public releve
{
private:
    type _prec;
    int _quantite;
public:
    precipitation(const type &prec, int quantite, const datereleve &d);
    // releve interface
public:
    std::string tostring() const override;
    std::string typereleve() const override;

    // releve interface
public:
    releve *clone() const override;
    const type & prec() const;
};

#endif // PRECIPITATION_H
