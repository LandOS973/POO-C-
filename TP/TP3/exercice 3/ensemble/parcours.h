#ifndef PARCOURS_H
#define PARCOURS_H
#include <iostream>

class parcours {
private:
    int tailleEnsemble;
public:
    parcours():tailleEnsemble(0){}
    void passerAuSuivant(){tailleEnsemble++;}
    int getTailleEnsemble() const {return tailleEnsemble;}
};

#endif // PARCOURS_H
