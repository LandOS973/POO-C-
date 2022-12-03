#ifndef INVADER_H
#define INVADER_H
#include "objetactif.h"

class invader : public objetactif
{
private:

public:
    invader(int xmin, int xmax,const direction &d, const position &p);
    // objet interface
public:
    void sortieflux(std::ostream &os) const override;
    void appliquerdeplacement() override;
};

#endif // INVADER_H
