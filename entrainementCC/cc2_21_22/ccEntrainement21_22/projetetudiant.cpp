#include "projetetudiant.h"
#include <algorithm>


const std::string &personnel::nom() const
{
    return _nom;
}

personnel::personnel(const std::string &nom) : _nom(nom)
{}

void personnel::sortieflux(std::ostream &os) const
{
    os<<afficheTypePersonne()<< " Nom : "<<_nom<<" ";
}

std::ostream & operator<<(std::ostream &os,personnel const &S){
    S.sortieflux(os);
    return os;
}

std::string personnel::afficheTypePersonne() const
{
    switch (typePers()) {
    case typePersonne::enseignant:return " enseignant "; break;
    case typePersonne::M1:return " M1 "; break;
    case typePersonne::M2:return " M2 "; break;
    default: return "";
        break;
    };
}


// ############################ ETUDIANT ##############################

int etudiant::count(0);

etudiant::etudiant(const std::string &nom) : personnel(nom), _numero(count++)
{}

void etudiant::sortieflux(std::ostream &os) const
{
    personnel::sortieflux(os);
    os<<"Numero : "<<_numero<<" ";
}

// ETUDIANT M1

etudiantM1::etudiantM1(const std::vector<languages> &languages, const std::string &nom) : etudiant(nom),
    _languages(languages)
{}

std::shared_ptr<etudiantM1> etudiantM1::fabrique(const std::vector<languages> &languages, const std::string &nom)
{
    if(languages.size() >= 2){
        return std::shared_ptr<etudiantM1>(new etudiantM1(languages,nom));
    }
    return nullptr;
}

typePersonne etudiantM1::typePers() const
{
    return typePersonne::M1;
}

bool etudiantM1::maitriselangage(const languages &l) const
{
    for(const auto &i: _languages){
        if(i == l) return true;
    }
    return false;
}

void etudiantM1::sortieflux(std::ostream &os) const
{
    etudiant::sortieflux(os);
    os<<"languages maîtrisés : ";
    for(auto const &i : _languages){
        switch (i) {
        case languages::cpp: std::cout<<"cpp ";break;
        case languages::js: std::cout<<"js ";break;
        case languages::python: std::cout<<"python ";break;
        case languages::php: std::cout<<"php ";break;
        default:
            break;
        }
    }
}

bool etudiantM1::expert() const
{
    return _languages.size() >= 3;
}
// ETUDIANT M2

etudiantM2::etudiantM2(int niveauExpertise, const std::string &nom) : etudiant(nom),
    _niveauExpertise(niveauExpertise)
{}

std::shared_ptr<etudiantM2> etudiantM2::fabrique(int niveauExpertise, const std::string &nom)
{
    if(niveauExpertise <= 10 && niveauExpertise >= 1){
        return std::shared_ptr<etudiantM2>(new etudiantM2(niveauExpertise,nom));
    }
    return nullptr;
}

typePersonne etudiantM2::typePers() const
{
    return typePersonne::M2;
}

bool etudiantM2::expert() const
{
    return _niveauExpertise > 7;
}

// ENSEIGNANT

enseignant::enseignant(int numBureau, const std::string &nom) : personnel(nom),
    _numBureau(numBureau)
{}

typePersonne enseignant::typePers() const
{
    return typePersonne::enseignant;
}

bool enseignant::expert() const
{
    return true;
}

// ##################" EXCEPTION ######################"


const char *exceptionuniversite::what() const noexcept
{
    return _msg.c_str();
}

exceptionuniversite::exceptionuniversite(const std::string &msg) : _msg(msg)
{}

// ################### UNIVERSITE ###################

bool universite::ajout(std::shared_ptr<personnel> p)
{
    for(const auto &i : _personnes){
        if(i->nom() == p->nom()) throw exceptionuniversite("Nom en double : " + i->nom());
    }
    _personnes.push_back(std::move(p));
    return true;
}

void universite::ajout(const projet &P)
{
    _ensembleDeProjet.push_back(P);
}

std::vector<std::shared_ptr<etudiantM1> > universite::rechercherdevs(const languages &l) const
{
    std::vector<std::shared_ptr<etudiantM1>> etudiants;
    for(const auto &i: _personnes){
        auto pp = std::dynamic_pointer_cast<etudiantM1>(i);
        if (pp != nullptr && pp->maitriselangage(l)){
            etudiants.push_back(pp);
        }
    }
    return etudiants;
}

std::ostream & operator<<(std::ostream &os,universite const &S){
    for(auto const &i : S._personnes){
        i->sortieflux(os);
    }
    return os;
}

void universite::saisiem2()
{
    try{
        std::cout<<"Saisi le niveau d'expertise";
        int x;
        std::cin>>x;
        std::string nom;
        std::cout<<"Saisi le nom ";
        std::cin>>nom;
        auto M2 = etudiantM2::fabrique(x,nom);
        while (M2 = nullptr) {
            std::cout<<"Saisi le niveau d'expertise";
            std::cin>>x;
            std::cout<<"Saisi le nom ";
            std::cin>>nom;
            M2 = etudiantM2::fabrique(x,nom);
        }
        ajout(M2);
    }catch(const exceptionuniversite &e){
        std::cout<<e.what();
    }

}

const std::vector<std::shared_ptr<personnel> > &universite::personnes() const
{
    return _personnes;
}


void projet::ajout(std::shared_ptr<personnel> p)
{
    int nbM1 = 0;
    int nbM2 = 0;
    int nbEns = 0;
    for(const auto &i : _participants){
        if(i->typePers() == typePersonne::M1) nbM1++;
        if(i->typePers() == typePersonne::M2) nbM2++;
        if(i->typePers() == typePersonne::enseignant) nbEns++;
    }
    for(const auto &i : _participants){
        if(i->typePers() == typePersonne::M2 && nbM2 >= nbM1)throw exceptionuniversite("Impossible d'ajouter un M2, il y en a déja trop par rapport aux M1");
        if(i->typePers() == typePersonne::enseignant && nbEns >= 2) throw exceptionuniversite("il y a deja trop d'enseignant dans ce projet");
    }
    _participants.push_back(std::move(p));
}

// ################### SAISI QT INTERFACE ######################

saisiem2qt::saisiem2qt(const universite &U):QWidget(),
    _U(U)
{
    // INITIALISTATION (passage par liste d'iniatialisation donne des warning)
    layout = new QHBoxLayout(window());
    _niveauexpertise = new QLineEdit("",this);
    _nom = new QLineEdit("",this);
    _quitter = new QPushButton("quitter",this);
    _ajouter = new QPushButton("Ajouter",this);
    _resultat = new QLabel("",this);
    layout->addWidget(_niveauexpertise);
    layout->addWidget(_nom);
    layout->addWidget(_ajouter);
    layout->addWidget(_quitter);
    layout->addWidget(_resultat);
    setWindowTitle("CC");
    connect(_quitter,&QPushButton::clicked,this,&saisiem2qt::close);
    connect(_ajouter,&QPushButton::clicked,this,&saisiem2qt::ajouter);
}

void saisiem2qt::ajouter()
{
    try{
        auto nom(_nom->text().toStdString());
        auto niveau(_niveauexpertise->text().toInt());
        auto M2 = etudiantM2::fabrique(niveau,nom);
        if(M2 == nullptr){
            _resultat->setText("<font color='black'>Niveau expertise invalide</font>");
        }else{
            _U.ajout(M2);
        }
        std::string resultat = "<font color='black'>Utilisateur " + M2->nom() + " a été ajouté !\n";
        for(auto const &i: _U.personnes()){
            resultat += i->nom() + " \n";
        }
        resultat += "</font>";
        _resultat->setText(QString::fromStdString(resultat));
    }catch(const exceptionuniversite &e){
        _resultat->setText("<font color='black'>Nom déja présent dans l'universite</font>");
    }
}


