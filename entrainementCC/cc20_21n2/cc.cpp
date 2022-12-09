#include "cc.h"

// ################### PERSONNE ######################
personne::personne(const std::string &nom) : _nom(nom)
{}

void personne::sortieflux(std::ostream &os) const
{
    os<<"Nom : "<<_nom<<" type : "<<retourneType()<<" ";
}

std::string personne::retourneType() const
{
    switch (typepers()) {
    case typersonne::enseignant : return "enseignant ";break;
    case typersonne::M2 : return "M2 ";break;
    case typersonne::M1 : return "M1 ";break;
    default: return ""; break;
    }
}

const std::string &personne::nom() const
{
    return _nom;
}

std::ostream & operator<<(std::ostream &os,personne const &S){
    S.sortieflux(os);
    return os;
}

// ################### ETUDIANT ######################

int etudiant::count(0);
etudiant::etudiant(const std::string &nom) : personne(nom),_numero(count++)
{}

void etudiant::sortieflux(std::ostream &os) const
{
    personne::sortieflux(os);
    os<<"Numero : "<<_numero;
}

// ################### M1 ######################

M1::M1(const std::vector<langages> &langages, const std::string &nom) : etudiant(nom),
    _langages(langages)
{}

std::shared_ptr<M1> M1::fabrique(const std::vector<langages> &langages, const std::string &nom)
{
    if(langages.size()<=2){
        return std::shared_ptr<M1>(new M1(langages,nom));
    }
    return nullptr;
}

typersonne M1::typepers() const
{
    return typersonne::M1;
}

bool M1::maitriselangage(const langages &L) const
{
    for(const auto &i : _langages){
        if(i == L) return true;
    }
    return false;
}

void M1::sortieflux(std::ostream &os) const
{
    etudiant::sortieflux(os);
    for(const auto &i : _langages){
        switch (i) {
        case langages::cpp:
            os<<"cpp ";
            break;
        case langages::js:
            os<<"js ";
            break;
        case langages::python:
            os<<"python ";
            break;
        case langages::php:
            os<<"php ";
            break;
        default:
            break;
        }
    }
}

bool M1::expert() const
{
    return _langages.size() >= 3;
}

// ################### M2 ######################

M2::M2(int niveau, const std::string &nom) : etudiant(nom),
    _niveau(niveau)
{}

std::shared_ptr<M2> M2::fabrique(int niveau, const std::string &nom)
{
    if(niveau >= 1 && niveau <= 10){
        return std::shared_ptr<M2>(new M2(niveau,nom));
    }
    return nullptr;
}

typersonne M2::typepers() const
{
    return typersonne::M2;
}

void M2::sortieflux(std::ostream &os) const
{
    etudiant::sortieflux(os);
    os<<"Niveau "<<_niveau;
}

bool M2::expert() const
{
    return _niveau > 7;
}

// ################### ENSEIGNANT ######################

typersonne ensegiant::typepers() const
{
    return typersonne::enseignant;
}

void ensegiant::sortieflux(std::ostream &os) const
{
    personne::sortieflux(os);
    os<<"Numero de bureau : "<<_numBureau;
}

bool ensegiant::expert() const
{
    return true;
}

ensegiant::ensegiant(int numBureau, const std::string &nom) : personne(nom),
    _numBureau(numBureau)
{}

//#################### EXCEPTION ##########################

exceptionuniversite::exceptionuniversite(const std::string &msg) : _msg(msg)
{}

const char *exceptionuniversite::what() const noexcept
{
    return _msg.c_str();
}


// ################### UNIVERSITE ######################

void unversite::ajouter(std::shared_ptr<personne> p)
{
    for(const auto &i : _personnes){
        if(p->nom() == i->nom()) throw exceptionuniversite("Nom en double : " + p->nom());
    }
    _personnes.push_back(std::move(p));
}

void unversite::ajouter(const projet &p)
{
    _projets.push_back(p);
}

std::vector<std::shared_ptr<personne> > unversite::rechercherdevs(const langages l) const
{
    std::vector<std::shared_ptr<personne>> p;
    for(const auto &i : _personnes){
        auto pp = std::dynamic_pointer_cast<M1>(i);
        if (pp != nullptr && pp->maitriselangage(l)){
            p.push_back(i);
        }
    }
    return p;
}

void projet::ajouter(std::shared_ptr<personne> p)
{
    int nbM1 = 0;
    int nbM2 = 0;
    int nbEns = 0;
    for(const auto &i : _personnes){
        if(i->typepers() == typersonne::M1) nbM1++;
        if(i->typepers() == typersonne::M2) nbM2++;
        if(i->typepers() == typersonne::enseignant) nbEns++;
    }
    if(nbEns >= 2 && p->typepers() == typersonne::enseignant) throw exceptionuniversite("deja trop d'enseignant");
    if(nbM1 <= nbM2 && p->typepers() == typersonne::M2) throw exceptionuniversite("deja trop de M2");
    _personnes.push_back(std::move(p));
}

//a mettre dans le .cc
// ################### SAISI QT INTERFACE ######################
saisi::saisi(unversite const &U):QWidget(),_U(U)
{
    // INITIALISTATION (passage par liste d'iniatialisation donne des warning)
    layout = new QHBoxLayout(window());
    _champ1 = new QLineEdit("",this);
    _champ2 = new QLineEdit("",this);
    _quitter = new QPushButton("quitter",this);
    _ajouter = new QPushButton("Ajouter",this);
    _resultat = new QLabel("",this);
    layout->addWidget(_champ1);
    layout->addWidget(_champ2);
    layout->addWidget(_ajouter);
    layout->addWidget(_quitter);
    layout->addWidget(_resultat);
    setWindowTitle("CC");
    connect(_quitter,&QPushButton::clicked,this,&saisi::close);
    connect(_ajouter,&QPushButton::clicked,this,&saisi::ajouter);
}

void saisi::ajouter()
{
    auto nom(_champ1->text().toStdString());
    auto niveau(_champ2->text().toInt()); // INT
    auto m2 = M2::fabrique(niveau,nom);
    if(m2 == nullptr){
        _resultat->setText("<font color='black'>Niveau invalide (champ 2)</font>");
        return;
    }
    try{
        _U.ajouter(m2);
        _resultat->setText(QString::fromStdString("<font color='black'>ajout de " + m2->nom() +"</font>"));
    }catch(const exceptionuniversite &e){
        _resultat->setText("<font color='black'>Nom déja présent dans l'universite (champ 1)</font>");
    }
}




