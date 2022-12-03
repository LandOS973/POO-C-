#ifndef LIVRES_H
#define LIVRES_H
#include "documentecrit.h"

class livres : public documentecrit
{
private:
    bool emprunt;
public:
    livres(bool emprunt, unsigned int nbpages, const std::string &nomAuteur, const std::string &titre);
    // document interface
public:
    bool empruntable() const override;
    std::string type() const override;
    document *clone() const override;
};

#endif // LIVRES_H
