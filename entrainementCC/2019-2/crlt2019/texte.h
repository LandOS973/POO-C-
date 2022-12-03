#ifndef TEXTE_H
#define TEXTE_H
#include "message.h"

class texte : public message
{
private:
    std::string _contenu;
public:
    texte(const std::string &contenu, const std::string &expediteur, const std::vector<std::string> &destinataires);

    // message interface
public:
    void sortieflux(std::ostream &os) const override;
};

#endif // TEXTE_H
