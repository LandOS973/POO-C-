#include "basemessages.h"

basemessages::basemessages()
{

}

void basemessages::ajout(const proposition &p)
{
    _propositions.push_back(p);
}

void basemessages::ajout(const reponse &p)
{
    _reponses.push_back(p);
}

void basemessages::ajout(const texte &p)
{
    _textes.push_back(p);
}

/*7. Écrire une méthode affichermessagesdate prenant comme paramètre un mois et un jour et
affichant la totalité des messages (propositions et réponses) concernant des réunions concernant
cette date*/
void basemessages::affichermessagesdate(int jour, int mois) const
{
    for(const auto &i: _propositions){
        if(i.reuniondate(jour,mois)) i.sortieflux(std::cout);
    }
    for(const auto &i:_reponses){
        if(i.h().getJour() == jour && i.h().getMois() == mois) i.sortieflux(std::cout);
    }
}

/*Écrire une méthode suppressioninteractive prenant comme paramètre un destinataire D,
affichant les messages ayant pour destinataire D et permettant de choisir un de ces messages pour le
supprimer. La suppression se fera par saisie de l’identifiant du message à supprimer, aucune
vérification n’est demandée.*/
void basemessages::suppressioninteractive(const std::string &D)
{
    for(const auto &i : _propositions){
        for(const auto &j : i.destinataires()){
            if(j == D) i.sortieflux(std::cout);
        }
    }
    for(const auto &i : _reponses){
        for(const auto &j : i.destinataires()){
            if(j == D) i.sortieflux(std::cout);
        }
    }
    for(const auto &i : _textes){
        for(const auto &j : i.destinataires()){
            if(j == D) i.sortieflux(std::cout);
        }
    }
    std::cout<<"Qui veux tu supprimer ? \n";
    int suppr;
    std::cin>>suppr;
    for (std::vector<proposition>::iterator it = _propositions.begin(); it != _propositions.end();){
        {
            if (it->id() == suppr)
                it = _propositions.erase(it);
            else
                ++it;
        }
    }
    for (std::vector<reponse>::iterator it = _reponses.begin(); it != _reponses.end();){
        {
            if (it->id() == suppr)
                it = _reponses.erase(it);
            else
                ++it;
        }
    }

}

/*Écrire une méthode repondre prenant comme paramètre une proposition P, un destinataire D de
cette proposition, et un horaire H. Si H fait partie des horaires proposés (dans P), la méthode ajoutera
à la base une réponse à P expédiée par D à l’expéditeur de P et contenant l’horaire H. Sinon, la
méthode ne fera rien.*/

void basemessages::repondre(const proposition &p, const std::string &D, const horaire &h)
{
    std::vector<std::string>destinataires;
    destinataires.push_back(p.expediteur());
    reponse R(h,p.id(),D,destinataires);
    _reponses.push_back(R);
}

void basemessages::afficher() const
{
    for(const auto &i : _propositions){
        i.sortieflux(std::cout);
    }
    for(const auto &i : _reponses){
        i.sortieflux(std::cout);
    }
    for(const auto &i : _textes){
        i.sortieflux(std::cout);
    }
}




