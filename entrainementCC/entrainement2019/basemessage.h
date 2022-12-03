#ifndef BASEMESSAGE_H
#define BASEMESSAGE_H
#include "message.h"
#include "reponse.h"
#include "proposition.h"
#include <memory>

class basemessage
{
private:
    std::vector<std::unique_ptr<message>>_messages;
public:
    basemessage();
    ~basemessage() = default;
    void ajoutMessage(std::unique_ptr<message> M);
    void affichemessage() const;
    void affichermessagesdate(unsigned int jour, unsigned int mois) const;
    void suppressioninteractive(const std::string & D);
    void repondre(const proposition &P, const std::string &destinataire, const horaire &H);
};

#endif // BASEMESSAGE_H
