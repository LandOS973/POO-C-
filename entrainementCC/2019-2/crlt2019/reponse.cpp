#include "reponse.h"

const horaire &reponse::h() const
{
    return _h;
}

reponse::reponse(const horaire &h, int idProp, const std::string &expediteur, const std::vector<std::string> &destinataires) : message(expediteur, destinataires),
    _h(h),
    _idProp(idProp)
{}

/*Écrire une méthode sortieflux prenant comme paramètre un flux de sortie et sortant sur le flux le
message sous la forme « 1 X->Y Z PROPOSITION CC C++ : 14/11-15h 15/11-8h » pour une
proposition, « 2 Y->X RÉPONSE À 1 : 14/11-15h » pour une réponse ou « 4 X->Y TEXTE
blabla » pour un texte.*/
void reponse::sortieflux(std::ostream &os) const
{
    message::sortieflux(os);
    os<<" REPONSE a "<< std::to_string(_idProp) <<" : "<< _h.tostring();
}
