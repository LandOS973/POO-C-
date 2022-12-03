#include "basemessage.h"

basemessage::basemessage()
{

}

void basemessage::ajoutMessage(std::unique_ptr<message> M)
{
    _messages.push_back(std::move(M));
}

void basemessage::affichemessage() const
{
    for (auto const & m : _messages) {
        m->sortieflux(std::cout);
    }
    std::cout<<"\n";
}

void basemessage::affichermessagesdate(unsigned int jour, unsigned int mois) const
{
    for(auto const & m: _messages){
        auto m1 = dynamic_cast<const reponse*>(m.get());
        if(m1 != nullptr && m1->reuniondate(jour,mois)){
            m1->sortieflux(std::cout);
        }
        auto m2 = dynamic_cast<const proposition*>(m.get());
        if(m2 != nullptr && m2->reuniondate(jour,mois)){
            m2->sortieflux(std::cout);
        }
    }
}

void basemessage::suppressioninteractive(const std::string &D)
{
    for(auto const & m : _messages){
        if(m->contientDestinataire(D)) m->sortieflux(std::cout);
    }
    int id;
    std::cout<<"\nSaisi l'id du message que tu veux supprimer\n";
    std::cin>>id;
    for (std::vector<std::unique_ptr<message>>::iterator it = _messages.begin(); it != _messages.end();)
        {
            if (it->get()->id() == id){
                it->reset();
                it = _messages.erase(it);

            }
            else
                ++it;
        }
    std::cout<<"Suppression terminee !\n";
    affichemessage();
}

/*Écrire une méthode repondre prenant comme paramètre une proposition P, un destinataire D de
cette proposition, et un horaire H. Si H fait partie des horaires proposés (dans P), la méthode ajoutera
à la base une réponse à P expédiée par D à l’expéditeur de P et contenant l’horaire H. Sinon, la
méthode ne fera rien.*/
void basemessage::repondre(const proposition &P, const std::string &destinataire, const horaire &H)
{
    for(const auto & h : P.getHoraires()){
        if(h.heure() == H.heure() && h.jour() == H.jour() && h.mois() == h.mois()){
            std::vector<std::string>V;
            V.push_back(P.expediteur());
            auto R = std::make_unique<reponse>(destinataire,V,P,H);
            ajoutMessage(std::move(R));
            return;
        }
    }
}


