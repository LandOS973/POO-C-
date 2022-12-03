#include "echequier.h"
#include "cavalier.h"
#include "pion.h"
#include "roi.h"
#include "fou.h"
#include <algorithm>
#include "tour.h"
#include "dame.h"
#include <fstream>


echequier::echequier()
{
    ajouterPiece(std::make_unique<tour>(couleur::BLANC,position(1,1)));
    ajouterPiece(std::make_unique<cavalier>(couleur::BLANC,position(2,1)));
    ajouterPiece(std::make_unique<fou>(couleur::BLANC,position(3,1)));
    ajouterPiece(std::make_unique<dame>(couleur::BLANC,position(4,1)));
    ajouterPiece(std::make_unique<roi>(couleur::BLANC,position(5,1)));
    ajouterPiece(std::make_unique<fou>(couleur::BLANC,position(6,1)));
    ajouterPiece(std::make_unique<cavalier>(couleur::BLANC,position(7,1)));
    ajouterPiece(std::make_unique<tour>(couleur::BLANC,position(8,1)));
    for (int i = 0; i < 8; ++i) {
        ajouterPiece(std::make_unique<pion>(couleur::BLANC,position(i+1,2)));
    }

    ajouterPiece(std::make_unique<tour>(couleur::NOIR,position(1,8)));
    ajouterPiece(std::make_unique<cavalier>(couleur::NOIR,position(2,8)));
    ajouterPiece(std::make_unique<fou>(couleur::NOIR,position(3,8)));
    ajouterPiece(std::make_unique<dame>(couleur::NOIR,position(4,8)));
    ajouterPiece(std::make_unique<roi>(couleur::NOIR,position(5,8)));
    ajouterPiece(std::make_unique<fou>(couleur::NOIR,position(6,8)));
    ajouterPiece(std::make_unique<cavalier>(couleur::NOIR,position(7,8)));
    ajouterPiece(std::make_unique<tour>(couleur::NOIR,position(8,8)));
    for (int i = 0; i < 8; ++i) {
        ajouterPiece(std::make_unique<pion>(couleur::NOIR,position(i+1,7)));
    }
}

echequier::echequier(const echequier &e)
{
    for(auto const & i : e._plateau){
        _plateau.push_back(i->clone());
    }
}

echequier &echequier::operator=(const echequier &e)
{
    if(this != &e){
        _plateau.clear();
        for(auto const &p : e._plateau){
            _plateau.push_back(p->clone());
        }
    }
    return *this;
}

void echequier::afficherBlanc(std::ostream &os) const
{
    // Voir affichage noir pour les vrais chad
    char plateau[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            plateau[i][j] = 'V';
        }
    }
    for(auto const &i : _plateau){
        plateau[i->P().vertical()-1][i->P().horizontal()-1] = i->name();
    }
    for (int i = 7; i >= 0; --i) {
        for (int j = 0; j < 8; ++j) {
            std::cout<<" ";
            if(plateau[i][j] == 'V') std::cout<<" ";
            else os<<plateau[i][j];
        }
        std::cout<<"\n";
    }
}

int echequier::valeurDuJoueur(const couleur &c) const
{
    int result = 0;
    for(const auto &i : _plateau){
        if(i->getColor() == c){
            result += i->valeur();
        }
    }
    return result;
}

void echequier::sauvegarde(std::ofstream &f) const
{
    if (!f.bad())
    {
        for(auto const &i:_plateau){
            f<<i->toString()<<std::endl;
        }
        f.close();
    }
}

bool echequier::deplacer(const position &source, const position &destination)
{
    couleur cd = static_cast<couleur>(3);
    for(auto &i : _plateau){
        if(i->P() == destination){
            cd = i->getColor();
        }
    }
    for(auto &i : _plateau){
        if(i->P() == source && i->getColor() != cd){
            i->deplacer(destination);
            return true;
        }
    }
    return false;
}

void echequier::afficherNoir(std::ostream &os) const
{
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            auto f = std::find_if(_plateau.begin(),_plateau.end(),[i,j](auto const &p){
                return (p->P().vertical() == i) && (p->P().horizontal() == j);
            });
            std::cout<<" ";
            if(f == _plateau.end()) std::cout<<" ";
            else os<<(*f)->name();
        }
        std::cout<<"\n";
    }
}

void echequier::ajouterPiece(std::unique_ptr<piece> p)
{
    _plateau.push_back(std::move(p));
}

void echequier::chargement(std::ifstream & os){
    while(!os.eof()){ //eof -> end of file !(package fstream)
        std::string line;
        os>>line;
        if(line.empty())
            break;couleur::BLANC,position(4,1);
        position p(line[2]-'0',line[3]-'0');
        couleur c((line[1]=='N')?couleur::NOIR:couleur::BLANC);
        std::unique_ptr<piece> np;
        switch(line[0]){
            case 'D':
                np=std::make_unique<dame>(c,p);
                break;
            case 'P':
                np=std::make_unique<pion>(c,p);
                break;
            case 'R':
                np=std::make_unique<roi>(c,p);
                break;
            case 'C':
                np=std::make_unique<cavalier>(c,p);
                break;
        }
        _plateau.push_back(std::move(np));//faut utiliser move !
    }
}


