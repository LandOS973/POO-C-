#include "message.h"

int message::count(0);

/*Écrire une méthode sortieflux prenant comme paramètre un flux de sortie et sortant sur le flux le
message sous la forme « 1 X->Y Z PROPOSITION CC C++ : 14/11-15h 15/11-8h » pour une
proposition, « 2 Y->X RÉPONSE À 1 : 14/11-15h » pour une réponse ou « 4 X->Y TEXTE
blabla » pour un texte.*/

void message::sortieflux(std::ostream &os) const
{
    os<<_id<<" "<<_expediteur<<" ";
    for(auto const & i : _destinataires){
        os<<i<<" ";
    }
}

const std::vector<std::string> &message::destinataires() const
{
    return _destinataires;
}

int message::id() const
{
    return _id;
}

const std::string &message::expediteur() const
{
    return _expediteur;
}

message::message(const std::string &expediteur, const std::vector<std::string> &destinataires) : _id(count++),
    _expediteur(expediteur),
    _destinataires(destinataires)
{}
