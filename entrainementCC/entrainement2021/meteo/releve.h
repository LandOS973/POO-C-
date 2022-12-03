#ifndef RELEVE_H
#define RELEVE_H
#include "datereleve.h"


/*Nous allons maintenant décrire les relevés. Chaque relevé a été effectué à une datereleve. Il y a trois
types de relevés :
temp pour un relevé de température exprimée en dixièmes de degrés celsius (int, par exemple 201
pour 20.1°C) ;
prec pour un relevé de précipitations pour lequel on mémorisera le type de précipitations (pluie,
grêle ou neige) ainsi que la quantité mesurée en millimètres (int) ;
vent pour la direction du vent (Nord, Sud, Est, Ouest).
Déclarer les classes pour représenter les relevés et écrire les constructeurs. Il n’y aura pas de
mutateurs : les valeurs des attributs seront fixées à la construction et ne seront pas modifiées ensuite.

. Écrire une méthode typereleve retournant une chaîne du type « Température », « Précipitations »
ou « Vent ».
*/

class releve
{
private:
    datereleve _d;
public:
    releve(const datereleve &d);
    virtual std::string typereleve() const = 0;
    virtual std::string tostring() const;
    void sortiesurflux(std::ostream & os) const;
    virtual releve * clone() const =0;
    const datereleve &d() const;
};


#endif // RELEVE_H
