#include "texte.h"

texte::texte(const std::string &contenu, const std::string &expediteur, const std::vector<std::string> &destinataires) : message(expediteur, destinataires),
    _contenu(contenu)
{}

/*Écrire une méthode sortieflux prenant comme paramètre un flux de sortie et sortant sur le flux le
message sous la forme « 1 X->Y Z PROPOSITION CC C++ : 14/11-15h 15/11-8h » pour une
proposition, « 2 Y->X RÉPONSE À 1 : 14/11-15h » pour une réponse ou « 4 X->Y TEXTE
blabla » pour un texte.*/
void texte::sortieflux(std::ostream &os) const
{
    message::sortieflux(os);
    os<<" TEXTE "<<_contenu;
}
