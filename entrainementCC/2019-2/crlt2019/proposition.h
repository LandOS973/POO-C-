#ifndef PROPOSITION_H
#define PROPOSITION_H
#include "message.h"
#include "horaire.h"
#include <list>

/*Une proposition de réunion contient un descriptif de réunion (chaîne) et un liste d’horaires
représentant les différents horaires possibles pour la réunion.*/

class proposition : public message
{
private:
    std::string _description;
    std::list<horaire>_horaires;
public:
    proposition(const std::string &description, const std::list<horaire> &horaires, const std::string &expediteur, const std::vector<std::string> &destinataires);
    // message interface
    void sortieflux(std::ostream &os) const override;
    bool reuniondate(int jour, int mois) const;
};

#endif // PROPOSITION_H
