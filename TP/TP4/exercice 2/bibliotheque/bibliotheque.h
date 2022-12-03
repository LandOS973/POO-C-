#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#include "document.h"
#include "video.h"
#include <vector>



class bibliotheque
{
private:
    std::vector<document *>_documents;
public:
    bibliotheque();
    bibliotheque(const bibliotheque &B);
    ~bibliotheque();
    bibliotheque &operator=(const bibliotheque & s);
    bibliotheque & copie(const bibliotheque & s);
    void ajouter(const document &p);
    int typeDeVideo(const support &S) const;
    friend std::ostream & operator<<(std::ostream &os,bibliotheque const &S);
    document const & acces(int i) const;
};

#endif // BIBLIOTHEQUE_H
