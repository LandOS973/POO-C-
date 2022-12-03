#ifndef REPONSE_H
#define REPONSE_H
#include "message.h"
#include "horaire.h"

/*Une réponse à une proposition contient un horaire choisi par une personne et l’identifiant de la
proposition concernée.*/

class reponse : public message
{
private:
    horaire _h;
    int _idProp;
public:
    reponse(const horaire &h, int idProp, const std::string &expediteur, const std::vector<std::string> &destinataires);

    // message interface
    const horaire &h() const;
    void sortieflux(std::ostream &os) const override;
};

#endif // REPONSE_H
