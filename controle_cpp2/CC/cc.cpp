#include "cc.h"

// ################### HORAIRE ######################

void horaire::setHeure(unsigned int newHeure)
{
    heure = newHeure;
}

unsigned int horaire::getHeure() const
{
    return heure;
}

unsigned int horaire::getJour() const
{
    return jour;
}

unsigned int horaire::getMois() const
{
    return mois;
}

horaire::horaire(unsigned int heure, unsigned int jour, unsigned int mois) : heure(heure),
    jour(jour),
    mois(mois)
{}

std::string horaire::toString() const
{
    return std::to_string(jour) + "/" + std::to_string(mois) + " - " + std::to_string(heure) + "h.";
}

bool horaire::operator==(const horaire &p) const
{
    return heure == p.heure && mois == p.mois && jour == p.jour;
}

bool horaire::operator!=(const horaire &p) const
{
    return heure != p.heure || mois != p.mois || jour != p.jour;
}

bool horaire::operator<=(const horaire &p) const
{
    if(mois < p.mois) return true;
    if(mois == p.mois && jour < p.jour) return true;
    if(mois == p.mois && jour <= p.jour && heure <= p.heure) return true;
    return false;
}

// ################### RDV ######################

std::ostream & operator<<(std::ostream &os,RDV const &S){
    S.sortieflux(os);
    return os;
}

RDV::RDV(const horaire &h, int duree) : _h(h),
    duree(duree)
{}

const horaire &RDV::h() const
{
    return _h;
}

int RDV::getDuree() const
{
    return duree;
}



bool RDV::decaler(int h)
{
    if(h + _h.getHeure() < 24){
        _h.setHeure(h + _h.getHeure());
        return true;
    }
    return false;
}

void RDV::sortieflux(std::ostream &os) const
{
    os<< type() + " - " + std::to_string(_h.getHeure()) + " - " + std::to_string(_h.getJour())<<" / " + std::to_string(_h.getMois()) + " duree " + std::to_string(duree) + "mn";
}

// ################### ENSEIGNANT ######################

creneauxens::creneauxens(unite matiere, const horaire &h) : RDV(h, 80),
    matiere(matiere)
{}

creneauxens::creneauxens(unite matiere, const horaire &h, int duree) : RDV(h, duree),
    matiere(matiere)
{}

bool creneauxens::decaler(int h)
{
    if(h + _h.getHeure() < 24 && (h <= 1 || h >= -1) ){
        _h.setHeure(h + _h.getHeure());
        return true;
    }
    return false;
}


void creneauxens::sortieflux(std::ostream &os) const
{
    RDV::sortieflux(os);
    os<<unite_toString()<<" ";
}

std::string creneauxens::type() const
{
    return "crenaux enseignant ";
}

unite creneauxens::getMatiere() const
{
    return matiere;
}

std::shared_ptr<creneauxens> creneauxens::fabrique(unite matiere, const horaire &h, int duree)
{
    if(h.getHeure()>= 8 && h.getHeure() <= 16 &&(h.getHeure() + duree < 24)){
        return std::shared_ptr<creneauxens>(new creneauxens(matiere,h,duree));
    }
         return nullptr;
}

std::string creneauxens::unite_toString() const
    {
         switch (matiere) {
         case unite::POO : return "POO ";break;
         case unite::Archi : return "Archi ";break;
         case unite::DCRA : return "DCRA ";break;
         default: return ""; break;
         }
}

std::shared_ptr<creneauxens> creneauxens::fabrique(unite matiere, const horaire &h)
{
    if(h.getHeure()>= 8 && h.getHeure() <= 16){
        return std::shared_ptr<creneauxens>(new creneauxens(matiere,h));
    }
    return nullptr;
}

// ################### MEDICAL ######################

medical::medical(const std::string &nomMed, const horaire &h) : RDV(h, 60),
    nomMed(nomMed)
{}

std::shared_ptr<medical> medical::fabrique(const std::string &nomMed, const horaire &h)
{
    if(h.getHeure() + 60 < 24){
        return std::shared_ptr<medical>(new medical(nomMed,h));
    }
    return nullptr;
}

const std::string &medical::getNomMed() const
{
    return nomMed;
}

bool medical::decaler(int h)
{
    return false;
}

void medical::sortieflux(std::ostream &os) const
{
    RDV::sortieflux(os);
    os<<nomMed;
}

std::string medical::type() const
{
    return "medical";
}

// ################### VACANCES ######################

vacances::vacances(const horaire &h,int duree) : RDV(h, duree)
{}

std::shared_ptr<vacances> vacances::fabrique(const horaire &h,int duree)
{
    if(duree > 60){
        return std::shared_ptr<vacances>(new vacances(h,duree));
    }
    return nullptr;
}

std::string vacances::type() const
{
    return "vacances";
}

// ################### CARNET ######################

void carnet::ajouter(std::shared_ptr<RDV> p)
{
    for(const auto &i : _contenu){
        if(p->h() == i->h()){
            throw exceptioncarenet("horaire " + p->h().toString());
        }
    }
    _contenu.push_back(p);
}

std::vector<std::shared_ptr<RDV> > carnet::examencarnet(const horaire &h) const
{
    std::vector<std::shared_ptr<RDV> > exams;
    for(const auto &i : _contenu){
        if(h <= i->h() && i->type() == "crenaux enseignant "){
            exams.push_back(i);
        }
    }
    return exams;
}

void carnet::supprimermatiere(const unite &m)
{
    for(const auto &i : _contenu){
        auto pp = std::dynamic_pointer_cast<creneauxens>(i);
        if (pp != nullptr && pp->getMatiere() == m){
            //_contenu.erase(i);
        }
    }
    /*for (std::vector<std::shared_ptr<RDV> >::iterator it = _contenu.begin(); it != _contenu.end();)
       {
        auto pp = std::dynamic_pointer_cast<creneauxens>(it);
        if (pp != nullptr && pp->getMatiere() == m){
            _contenu.erase(i);
        }else{
            ++it;
        }
    }*/
}

void carnet::saisimedical()
{
    std::cout<<"saisi un horaire, et le nom du medecin ";
    unsigned int heure,jour,mois;
    std::cin>>heure;
    std::cin>>jour;
    std::cin>>mois;
    std::string nom;
    std::cin>>nom;
    horaire h(heure,jour,mois);
    auto M = medical::fabrique(nom,h);
    while (M == nullptr) {
        std::cout<<"saisi un horaire, et le nom du medecin ";
        std::cin>>heure;
        std::cin>>jour;
        std::cin>>mois;
        std::cin>>nom;
        horaire h(heure,jour,mois);
        auto M = medical::fabrique(nom,h);
    }
    ajouter(M);
}

//#################### EXCEPTION ##########################

exceptioncarenet::exceptioncarenet(const std::string &msg) : _msg(msg)
{}

const char *exceptioncarenet::what() const noexcept
{
    return _msg.c_str();
}

// ################### SAISI QT INTERFACE ######################
qt_decaler::qt_decaler(std::shared_ptr<RDV> R):QWidget()
{
    // INITIALISTATION (passage par liste d'iniatialisation donne des warning)
    _R = R;
    layout = new QHBoxLayout(window());
    _champ1 = new QLineEdit("",this);
    _quitter = new QPushButton("quitter",this);
    _decaler = new QPushButton("decaler",this);
    _resultat = new QLabel("",this);
    _horaire = new QLabel("",this);
    _horaire->setText("horaire");
    layout->addWidget(_horaire);
    layout->addWidget(_champ1);
    layout->addWidget(_decaler);
    layout->addWidget(_quitter);
    layout->addWidget(_resultat);
    setWindowTitle("CC");
    connect(_quitter,&QPushButton::clicked,this,&qt_decaler::close);
    connect(_decaler,&QPushButton::clicked,this,&qt_decaler::decaler);
}

void qt_decaler::decaler()
{
    int niveau(_champ1->text().toInt()); // INT
    if(_R->decaler(niveau)){
        _resultat->setText(QString::fromStdString("examen décalé !" + std::to_string(niveau)));
    }else{
        _resultat->setText("decalage impossible");
    }
}




