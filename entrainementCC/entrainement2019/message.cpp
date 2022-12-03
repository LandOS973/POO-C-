#include "message.h"

int message::_compteur(0);

message::message(std::string expediteur, std::vector<std::string> destinataire)
    : _id(_compteur++), _expediteur(expediteur), _destinataire(destinataire)
{}


int message::id() const
{
    return _id;
}

const std::string &message::expediteur() const
{
    return _expediteur;
}

const std::vector<std::string> &message::destinataire() const
{
    return _destinataire;
}

bool message::contientDestinataire(const std::string &D)
{
    for(const auto & d : destinataire()){
        if(d == D) return true;
    }
    return false;
}

