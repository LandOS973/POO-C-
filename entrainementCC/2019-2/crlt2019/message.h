#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <vector>
#include <iostream>
/*Écrire une méthode sortieflux prenant comme paramètre un flux de sortie et sortant sur le flux le
message sous la forme « 1 X->Y Z PROPOSITION CC C++ : 14/11-15h 15/11-8h » pour une
proposition, « 2 Y->X RÉPONSE À 1 : 14/11-15h » pour une réponse ou « 4 X->Y TEXTE
blabla » pour un texte.*/

class message
{
private:
    static int count;
    int _id;
    std::string _expediteur;
    std::vector<std::string> _destinataires;
public:
    virtual ~message() = default;
    message(const std::string &expediteur, const std::vector<std::string> &destinataires);
    virtual void sortieflux(std::ostream &os) const;


    const std::vector<std::string> &destinataires() const;
    int id() const;
    const std::string &expediteur() const;
};

#endif // MESSAGE_H
