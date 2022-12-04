#include "cc.h"

// ################### GROUPE ######################

int groupe::count(0);

int groupe::annee() const
{
    return _annee;
}

const std::string &groupe::nom() const
{
    return _nom;
}

int groupe::numero() const
{
    return _numero;
}

groupe::groupe(int annee, const std::string &nom) : _annee(annee),
    _nom(nom), _numero(count++)
{}

bool groupe::operator==(const groupe &g) const
{
    return ((g._annee == _annee) && (g._nom == _nom) && (g._numero == _numero));
}

// ################### ELEMENT ######################

element::element(unsigned int importance) : importance(importance)
{}

void element::setImportance(unsigned int newImportance)
{
    importance = newImportance;
}

unsigned int element::getImportance() const
{
    return importance;
}

void element::sortieflux(std::ostream &os) const
{
    os<<" Importance : "<<importance;
}

std::ostream & operator<<(std::ostream &os,element const &S){
    S.sortieflux(os);
    return os;
}
// ###################  FICHER ######################

fichier::fichier(const std::string &url) : _url(url) , element(1)
{}

void fichier::sortieflux(std::ostream &os) const
{
    os<<"Fichier ";
    element::sortieflux(os);
    os<<" - url : "<<_url<<"\n";
}

std::unique_ptr<element> fichier::clone() const
{
    return std::make_unique<fichier>(*this);
}

// ################### PAGE ######################

page::page(int importance) : element(importance){}

void page::ajouterSection(const section &s)
{
    _section.push_back(s);
}

void page::sortieflux(std::ostream &os) const
{
    os<<"Page ";
    element::sortieflux(os);
    int x = 0;
    for(const auto &i : _section){
       if(i.visible) x++;
    }
    os<<" "<<_section.size() <<" sections dont "<<x<<" visibles \n";

}

std::unique_ptr<element> page::clone() const
{
    return std::make_unique<page>(*this);
}

std::shared_ptr<page> page::fabrique(int importance)
{
    if(importance>=0 && importance<=10) return std::shared_ptr<page>(new page(importance));
    return nullptr;
}

// ################### DEVOIR ######################


devoir::devoir(std::shared_ptr<element> e = nullptr) : _e(std::move(e)), element(10)
{}

devoir::devoir(const devoir &d):element(10), _e(std::move(d._e)){}

void devoir::ajouterRendu(const rendu &r)
{
    _rendu = r;
}

void devoir::sortieflux(std::ostream &os) const
{
    os<<"Devoir ";
    element::sortieflux(os);
    os<<" "<<_rendu.contenu<<" ";
    if(_e == nullptr) os << "sujet indefini \n";
    else{
        os<<" Sujet défini : ";
        _e->sortieflux(os);
    }
}

std::unique_ptr<element> devoir::clone() const
{
    return std::make_unique<devoir>(*this);
}

// ################### ESPACE ######################

int espace::count(0);

std::shared_ptr<espace> espace::fabrique(const std::string &nom)
{
    if(nom != "") return std::shared_ptr<espace>(new espace(nom));
    return nullptr;
}

espace::espace(const std::string &nom): _nom(nom), _numero(espace::count++)
{
}

void espace::ajoutergroupe(const groupe &g)
{
    for(const auto &i : _groupes){
        if(i == g) return;
    }
    _groupes.push_back(g);
}

void espace::ajouterelement(std::unique_ptr<element> e)
{
    _elements.push_back(std::move(e));
}

espace &espace::espace::operator=(const espace &s)
{
    if(this != &s){
        _groupes.clear();
        _elements.clear();
        for(auto const &p : s._elements){
            _elements.push_back(p->clone());
        }
        for(auto const &p : s._groupes){
            _groupes.push_back(p);
        }
    }
    return *this;
}

espace::espace(const espace &s)
{
    for(auto const &p : s._elements){
        _elements.push_back(p->clone());
    }
    for(auto const &p : s._groupes){
        _groupes.push_back(p);
    }
}

std::ostream & operator<<(std::ostream &os,espace const &S){
    os<<S._nom<<"\n";
    for(auto const &p : S._elements){
        p->sortieflux(os);
    }
    return os;
}





