#ifndef PROPOSITION_H
#define PROPOSITION_H
#include "message.h"
#include <list>
#include "horaire.h"

class proposition : public message
{
private:
    std::list<horaire>horaires;
    std::string description;
public:
    proposition();
    proposition(const std::list<horaire> &horaires, const std::string &description, const std::string &expediteur, const std::vector<std::string> &destinataire);
    void sortieflux(std::ostream & os) const;
    bool reuniondate(unsigned int jour, unsigned int mois) const;
    const std::list<horaire> &getHoraires() const;
    const std::string &getDescription() const;
};

#endif // PROPOSITION_H
