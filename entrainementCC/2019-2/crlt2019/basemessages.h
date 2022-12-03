#ifndef BASEMESSAGES_H
#define BASEMESSAGES_H
#include <vector>
#include "proposition.h"
#include "reponse.h"
#include "texte.h"

/*Écrire une classe basemessages représentant un ensemble des messages, et munir cette classe (au
moins) de méthodes permettant de construire un ensemble vide et ajouter un message.*/
class basemessages
{
private:
    std::vector<proposition>_propositions;
    std::vector<reponse>_reponses;
    std::vector<texte>_textes;
public:
    basemessages();
    void ajout(const proposition &p);
    void ajout(const reponse &p);
    void ajout(const texte &p);
    void affichermessagesdate(int jour, int mois) const;
    void suppressioninteractive(const std::string &D);
    void repondre(const proposition &p, const std::string &D, const horaire &h);
    void afficher() const;
};


#endif // BASEMESSAGES_H
