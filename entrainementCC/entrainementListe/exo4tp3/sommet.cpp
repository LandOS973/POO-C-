#include "sommet.h"

int sommet::count(0);

int sommet::id() const
{
    return _id;
}

const std::string &sommet::etiquette() const
{
    return _etiquette;
}


sommet::sommet(const std::string &etiquette) : _etiquette(etiquette), _id(count++)
{}


/*ajouterarc prenant comme paramètre un identifiant de sommet extrémité et une étiquette d’arc et
rajoutant l’arc sortant au sommet. S’il existe déjà un arc sortant vers le même sommet, l’étiquette de
celui-ci sera remplacée par l’étiquette passée en paramètre (il ne peut y avoir deux arcs entre deux
sommets donnés).*/

void sommet::ajouterarc(int id, const std::string &etiquette)
{
    arcsortant A={etiquette,id};
    for(auto &i : _arcsortants){
        if(A.extremite == i.extremite){
            i.etiquette=etiquette;
            return;
        }
    }
    _arcsortants.push_back(A);
}

void sommet::supprimerarc(int id)
{
    for (std::list<arcsortant>::iterator i=_arcsortants.begin(); i!=_arcsortants.end(); i++)
    {
        if(i->extremite == id){
            i = _arcsortants.erase(i);
        }
    }
}

void sommet::toutsupprimer()
{
    _arcsortants.clear();
}

/*dot_etiquette prenant comme paramètre un flux de sortie et envoyant sur ce flux une construction
du type « identifiant [label="etiquette"] ; » en préfixant l’identifiant par un « c ». Par exemple pour
un sommet dont l’identifiant est 1 et l’étiquette est « a », cette méthode sortira « c1 [label="a"]; ».
dot_arcssortants prenant comme paramètre un flux de sortie et envoyant sur ce flux de sortie, pour
chacun des arcs sortants, une construction du type « identifiant du sommet -> identifiant du
sommet ; ». Par exemple, pour un sommet dont l’identifiant est 1 et ayant deux arcs vers les sommets
2 et 3, cette méthode sortira sur le flux « c1 -> c2 ; c1 -> c3 ; ». Si l’étiquette de l’arc n’est pas la
chaîne vide, on sortira cette étiquette de la même façon que pour un sommet, c’est-à-dire
« [label="etiquette"] » juste avant le « ; ». Voir l’exemple en bas de la question suivante, pour l’arc
allant de c1 à c3 et étiqueté « Avion ». */

void sommet::dot_etiquette(std::ostream &os) const
{
    os<<"c"+std::to_string(_id)+" [label=\"" +_etiquette +"\"];\n";
    for(auto const &i : _arcsortants){
        os<<"c"+std::to_string(_id)+"->"+"c"+std::to_string(i.extremite);
        if(i.etiquette != ""){
            os<<" [label=\""+_etiquette+"\"];\n";
        }
    }
}




















