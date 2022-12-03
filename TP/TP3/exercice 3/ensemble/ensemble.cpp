#include "ensemble.h"

void ensemble::ajout(int x){
    if(appartient(x)) return;
    ajoutSansVerif(x);
}

ensemble::~ensemble()
{

}

void ensemble::unionE(ensemble & E1, ensemble & E2) {
    for (parcours p;  p.getTailleEnsemble()< E1.estFini(); p.passerAuSuivant()) {
        E2.ajout(E1.acces(p.getTailleEnsemble()));
    }
    for (parcours p;  p.getTailleEnsemble()< E2.estFini(); p.passerAuSuivant()) {
        E1.ajout(E2.acces(p.getTailleEnsemble()));
    }
}
void ensemble::intersection(ensemble & E1, ensemble & E2){
    for (parcours p;  p.getTailleEnsemble()< E1.estFini(); p.passerAuSuivant()) {
        if(!E2.appartient(E1.acces(p.getTailleEnsemble()))){
              E2.enlever(p.getTailleEnsemble());
        }
    }
    for (parcours p;  p.getTailleEnsemble()< E2.estFini(); p.passerAuSuivant()) {
        if(!E1.appartient(E2.acces(p.getTailleEnsemble()))){
              E1.enlever(p.getTailleEnsemble());
        }
    }
}
