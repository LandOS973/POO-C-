#ifndef TEXTE_H
#define TEXTE_H
#include "message.h"


class texte : public message
{
private:
    std::string _text;
public:
    texte(const std::string &text, const std::string &expediteur, const std::vector<std::string> &destinataire);
    void sortieflux(std::ostream& os) const;
};

#endif // TEXTE_H
