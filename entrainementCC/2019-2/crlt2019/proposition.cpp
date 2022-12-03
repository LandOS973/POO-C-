#include "proposition.h"

proposition::proposition(const std::string &description, const std::list<horaire> &horaires, const std::string &expediteur, const std::vector<std::string> &destinataires) : message(expediteur, destinataires),
    _description(description),
    _horaires(horaires)
{}


/*Écrire une méthode sortieflux prenant comme paramètre un flux de sortie et sortant sur le flux le
message sous la forme « 1 X->Y Z PROPOSITION CC C++ : 14/11-15h 15/11-8h » pour une
proposition, « 2 Y->X RÉPONSE À 1 : 14/11-15h » pour une réponse ou « 4 X->Y TEXTE
blabla » pour un texte.*/
void proposition::sortieflux(std::ostream &os) const
{
    message::sortieflux(os);
    os<<" PROPOSITION " << _description;
    for(const auto &i : _horaires){
        os<<i.tostring()<<" \n";
    }
}


/*Écrire une méthode reuniondate prenant comme paramètre un jour et un mois, et retournant vrai si
le message concerne une proposition de réunion dans laquelle (au moins) un horaire possible est à
cette date ou une réponse avec cette date ; faux sinon.*/
bool proposition::reuniondate(int jour, int mois) const
{
    for(const auto &i: _horaires){
        if(i.getJour() == jour && i.getMois() == mois) return true;
    }
    return false;
}
