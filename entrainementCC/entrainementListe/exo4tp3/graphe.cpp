#include "graphe.h"
#include <algorithm>

graphe::graphe()
{

}

/*Écrire une classe graphe contenant une liste de sommet. Munir cette classe des méthodes suivantes :
ajoutersommet prenant comme paramètre une étiquette de sommet et retournant l’identifiant du
sommet ajouté.
ajouterarc prenant comme paramètre deux identifiants de sommets et une étiquette d’arc et
ajoutant un arc entre les deux sommets, étiqueté par l’étiquette passée. La méthode retournera true
si l’ajout s’est correctement déroulé, et false s’il n’a pu être fait (identifiant de sommets introuvables).
supprimersommet prenant un identifiant et supprimant le sommet (ainsi que tous les arcs sortants et
entrants de ce sommet).
dot_sortie prenant comme paramètre un flux de sortie et sortant sur ce flux une expression du type
« digraph G { les sorties de dot_etiquette pour chacun des sommets, les sorties de
dot_arcssortants pour chacun des sommets } ». Par exemple, ci-dessous, un graphe et le fichier au
format dot associé.*/

int graphe::ajoutersommet(const std::string etiquette)
{
    sommet S(etiquette);
    _sommets.push_back(S);
    return S.id();
}

bool graphe::ajouterarc(int id1, int id2, const std::string &etiquette)
{
    std::list<sommet>::iterator it;
    for (it = _sommets.begin(); it != _sommets.end(); ++it){
        if(it->id() == id1){
            it->ajouterarc(id2,etiquette);
            return true;
        }
    }
    return false;
}

/*Digraph G {
c1 [label="Paris"];
c1 -> c3 [label="Avion"];
c3 [label="Nantes"];
}
4. Le fichier source ci-dessous g*/

void graphe::dot_sortie(std::ostream &os) const
{
    os<<"digraph G{\n";
    for(auto const &i : _sommets){
        i.dot_etiquette(os);
    }
    os<<"}";
}

void graphe::supprimersommet(int id)
{
    std::list<sommet>::iterator it;
    for (it = _sommets.begin(); it != _sommets.end(); ++it){
        if(it->id() == id){
            it->toutsupprimer();
            it = _sommets.erase(it);
        }
    }
}
