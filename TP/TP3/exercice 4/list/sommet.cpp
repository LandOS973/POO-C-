#include "sommet.h"

const std::list<arc> &sommet::arcs() const
{
    return _arcs;
}

sommet::sommet(std::string etiquette):_id(_compteur++),_etiquette(etiquette){}

int sommet::_compteur(1);

unsigned int sommet::id() const
{
    return _id;
}

const std::string &sommet::etiquette() const
{
    return _etiquette;
}

void sommet::ajouterArc(identifiant id, const std::string &etiquette)
{
    std::list<arc>::iterator it;
    for (it = _arcs.begin(); it != _arcs.end(); ++it){
        if(it->extremite == id){
            it->etiquette = etiquette;
            return;
        }
    }
    arc A{etiquette, id};
    _arcs.push_back(A);
}

void sommet::supprimerarc(identifiant id)
{
    std::list<arc>::iterator it;
    for (it = _arcs.begin(); it != _arcs.end(); ++it){
        if(it->extremite == id){
            _arcs.erase(it);
            return;
        }
    }
}

void sommet::supprimertousarcs()
{
    _arcs.clear();
}

void sommet::dot_etiquette(std::ostream &out) const
{
    out<<"c"<<_id<<" [label=\""<<_etiquette<<"\"];"<<std::endl;
}

void sommet::dot_arcsortant(std::ostream &out) const
{
    std::list<arc>::const_iterator it;
    for (it = _arcs.begin(); it != _arcs.end(); ++it){
        out<<"c"<<_id<<" -> "<<"c"<<it->extremite;
        if(it->etiquette != "") out<<" [label=\""<<it->etiquette<<"\"]";
        out<<" ;"<<std::endl;
    }
}




