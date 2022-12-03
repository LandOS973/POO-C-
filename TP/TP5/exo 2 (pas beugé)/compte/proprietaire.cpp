#include "proprietaire.h"

std::ostream & operator<<(std::ostream & os,proprietaire const &p){
    p.sortieflux(os);
    return os;
}

void proprietaire::sortieflux(std::ostream & os)const{
    os<<typeprop()<<" Nom: "<<nom()<<" Adresse: "<<adresse();
}

std::ostream& operator<<(std::ostream & os,type t){
    switch(t){
        case type::personne: os<<"Personne";break;
        case type::societe: os<<"Societe";break;
        case type::couple: os<<"Couple";break;
    }
    return os;
}

void personne::sortieflux(std::ostream &os) const{
    proprietaire::sortieflux(os);
    os<<"Naissance: "<<_naissance;
}

void societe::sortieflux(std::ostream &os) const{
    proprietaire::sortieflux(os);
    os<<"Gerant: "<<(*(this->_gerant));
}

std::shared_ptr<proprietaire> proprietaire::fabrique(std::string const & nom,std::string const & addr,std::string const & nais){
    return std::shared_ptr<personne>(new personne(nom,addr,nais));
}

std::shared_ptr<proprietaire> proprietaire::fabrique(std::string const & nom,std::string const & addr,std::shared_ptr<proprietaire> p){
    if(p->typeprop()==type::personne){
        return std::shared_ptr<societe>(new societe(nom,addr,std::dynamic_pointer_cast<personne>(p)));
    }
    return nullptr;
}

std::shared_ptr<proprietaire> proprietaire::fabrique(std::shared_ptr<proprietaire> p1, std::shared_ptr<proprietaire> p2){
    if((p1->typeprop()==type::personne) && (p2->typeprop()==type::personne) && p1->adresse()==p2->adresse()){
        return std::shared_ptr<couple>(new couple(std::dynamic_pointer_cast<personne>(p1),std::dynamic_pointer_cast<personne>(p2)));
    }
    return nullptr;
}

unsigned int compte::_compteur = 0;

compte::compte(std::shared_ptr<proprietaire> p, float m):_prop(p),_montant(m),_numero(++_compteur){}

float compte::montant() const
{
    return _montant;
}

void compte::setMontant(float newMontant)
{
    _montant = newMontant;
}

const std::shared_ptr<proprietaire> &compte::prop() const
{
    return _prop;
}

void compte::sortieflux(std::ostream &os) const
{
    _prop->sortieflux(os);
    os<<"Numero : "<<_numero;
    os<<"Montant : "<<_montant;
}

void compte::appliquerInteret()
{
    _montant += _montant * taux();
}

bool compte::verser(float m)
{
    if(montantautorise(_montant + m)){
        _montant += m;
        return true;
    }
    return false;
}

bool compte::retirer(float m)
{
    if(montantautorise(_montant -m)){
        _montant -= m;
        return true;
    }
    return false;
}

bool compte::virer(compte &dest, float m)
{
    float commission=(_prop == dest._prop ? 0.0 : 1.0);
    if(montantautorise(_montant - m - commission) && montantautorise(dest._montant + m)){
        if(_montant > (m + commission)){
                _montant -= (m + commission);
                dest._montant += m;
                return true;
        }
    }
    return false;
}

// COMPTE COURANT

void compteCourant::setDecouvert(float newDecouvert)
{
    _decouvert = newDecouvert;
}

std::shared_ptr<compte> compteCourant::clone() const
{
    return std::make_shared<compteCourant>(*this);
}

void compteCourant::sortieflux(std::ostream &os) const
{
    compte::sortieflux(os);
    os<<"Découvert : "<<_decouvert<<std::endl;
}


compteCourant::compteCourant(const std::shared_ptr<proprietaire> &p, float m) : compte(p, m), _decouvert(0)
{}

// ################### LDD ####################

float LDD::_tauxinteret = 0.00075;

void LDD::setTauxinteret(float newTauxinteret)
{
    _tauxinteret = newTauxinteret;
}

LDD::LDD(const std::shared_ptr<proprietaire> &p, float m) : compte(p, m)
{}

std::shared_ptr<LDD> LDD::fabrique(const std::shared_ptr<proprietaire> &p, float m)
{
    if(m>=15 && m<=12000){
        return std::shared_ptr<LDD>(new LDD(p,m));
    }
    return nullptr;
}

std::shared_ptr<compte> LDD::clone() const
{
    return std::make_shared<LDD>(*this);
}

void LDD::sortieflux(std::ostream &os) const
{
    compte::sortieflux(os);
    os<<"Taux d'interet : "<<_tauxinteret<<std::endl;
}

bool LDD::montantautorise(float m) const
{
    return (15 <= m) && (m <= 12000);
}

// #################### LEP ##################

/*  le LEP doit avoir pour
propriétaire une personne physique, doit contenir de 30 à 7700 €, et rapporte 1,25 % par an. À noter
que l’application des intérêts peut entraîner un dépassement du plafond du compte, mais cela est
autorisé.*/

LEP::LEP(const std::shared_ptr<proprietaire> &p, float m) : compte(p, m)
{}

void LEP::setTauxinteret(float newTauxinteret)
{
    _tauxinteret = newTauxinteret;
}

float LEP::_tauxinteret = 0.00125;

std::shared_ptr<LEP> LEP::fabrique(const std::shared_ptr<proprietaire> &p, float m)
{
    auto pp = std::dynamic_pointer_cast<personne>(p);
    if(m>=30 && m<=7700 && pp != nullptr){
        return std::shared_ptr<LEP>(new LEP(p,m));
    }
    return nullptr;
}

std::shared_ptr<compte> LEP::clone() const
{
    return std::make_shared<LEP>(*this);
}

void LEP::sortieflux(std::ostream &os) const
{
    compte::sortieflux(os);
    os<<"Taux d'interet : "<<_tauxinteret<<std::endl;
}

bool LEP::montantautorise(float m) const
{
    return (30 <= m) && (m <= 7700);
}

// ####################### BANQUE #########################

void banque::ajouter(std::shared_ptr<compte> C)
{
    _comptes.push_back(C->clone());
}

void banque::appliquerTauxInteret()
{
    for(auto &i : _comptes){
        auto lep = dynamic_cast<LEP*>(i.get());
        if(lep != nullptr) lep->appliquerInteret();
        auto ldd = dynamic_cast<LDD*>(i.get());
        if(ldd != nullptr) ldd->appliquerInteret();
    }
}

void banque::sortieflux(std::ostream &os) const
{
    for(const auto &i: _comptes){
        i->sortieflux(os);
    }
}

std::shared_ptr<proprietaire> banque::chercheproprietaire(const std::string &s) const
{
    for(const auto &i: _comptes){
        if(i->prop()->nom() == s) return i->prop();
    }
    return nullptr;
}

std::vector<int> banque::comptes(const proprietaire &p) const
{
    std::vector<int> ids;
    for(const auto &i:_comptes){

    }
    return ids;
}

std::ostream & operator<<(std::ostream &os,banque const &B){
    B.sortieflux(os);
    return os;
}
