#include "graphe.h"

graphe::graphe()
{
}

identifiant graphe::ajoutersommet(std::string etiquette)
{
    sommet S(etiquette);
    _sommets.push_back(S);
    return S.id();
}

bool graphe::ajouterarc(identifiant a, identifiant b, std::string etiquette)
{
    std::list<sommet>::iterator it;
    for (it = _sommets.begin(); it != _sommets.end(); ++it){
        if(it->id() == a){
            it->ajouterArc(b,etiquette);
            return true;
        }
    }
    return false;
}

void graphe::supprimersommet(identifiant id)
{
    std::list<sommet>::iterator it;
    for (it = _sommets.begin(); it != _sommets.end(); ++it){
        if(it->id() == id){
            it->supprimertousarcs();
            _sommets.erase(it);
            return;
        }
    }
}

void graphe::dot_sortie(std::ostream &out) const
{
    out<<"Digraph G"<<"{"<<std::endl;
    std::list<sommet>::const_iterator it;
    for (it = _sommets.begin(); it != _sommets.end(); ++it){
        it->dot_etiquette(out);
        it->dot_arcsortant(out);
    }
    out<<"}";
}





