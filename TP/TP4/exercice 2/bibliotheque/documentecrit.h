#ifndef DOCUMENTECRIT_H
#define DOCUMENTECRIT_H
#include "document.h"

class documentecrit : public document
{
private:
    unsigned int _nbpages;
public:
    documentecrit(unsigned int nbpages, const std::string &nomAuteur, const std::string &titre);
    virtual ~documentecrit() = default;
    // document interface
public:
    float cout() const override;
    void sortie(std::ostream &os) const override;
};

#endif // DOCUMENTECRIT_H
