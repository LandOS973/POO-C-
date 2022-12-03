#ifndef REPONSE_H
#define REPONSE_H
#include "horaire.h"
#include "message.h"
#include "proposition.h"
#include <iostream>

class reponse : public message
{
private:
    unsigned int _idProp;
    horaire _H;
public:
    reponse(const std::string &expediteur, const std::vector<std::string> &destinataire, const proposition &P, const horaire &H);
    void sortieflux(std::ostream & os) const;
    bool reuniondate(unsigned int jour, unsigned int mois) const;
};

#endif // REPONSE_H
