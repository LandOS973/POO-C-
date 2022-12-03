#ifndef PERIODIQUE_H
#define PERIODIQUE_H
#include "documentecrit.h"

class periodique : public documentecrit
{
private:
    int _numero;
public:
    periodique(int numero, unsigned int nbpages, const std::string &nomAuteur, const std::string &titre);

    // document interface
public:
    bool empruntable() const override;
    std::string type() const override;
    void sortie(std::ostream &os) const override;
    document *clone() const override;
};

#endif // PERIODIQUE_H
