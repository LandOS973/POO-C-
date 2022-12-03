#include "jeu.h"

//joueur(int xmin, int xmax, const direction &d, const taille &t, const position &p);
jeu::jeu() : _J(10,310,direction::stop,taille(9,8),position(144,80))
{

}

bool jeu::ajouter(const projectile &p)
{
    for(auto const &i : _projectiles){
        if(i.pos() == p.pos()) return false;
    }
    _projectiles.push_back(p);
    return true;
}

void jeu::ajouter(const invader &i)
{
    _invaders.push_back(i);
}

void jeu::tirjoueur()
{
    projectile p(position(_J.pos().x(),_J.pos().y()-1));
    ajouter(p);
}

void jeu::tourdejeu()
{
    for(auto &i:_invaders){
        i.appliquerdeplacement();
    }
    for(auto &i:_projectiles){
        i.appliquerdeplacement();
    }
    projectiledisparition();
    //projectilecolision(); commenté car boucle infini
    _J.appliquerdeplacement();
}

void jeu::afficherjeu() const
{
    for(auto const &i:_invaders){
        std::cout<<i;
    }
    for(auto const &i:_projectiles){
        std::cout<<i;
    }
    std::cout<<_J;
}

void jeu::projectiledisparition()
{
    for (std::vector<projectile>::iterator it = _projectiles.begin(); it != _projectiles.end();){
            if (it->pos().y() == 0)
                it = _projectiles.erase(it);
            else
                ++it;
    }
}

void jeu::projectilecolision()
{
    for (std::vector<projectile>::iterator it = _projectiles.begin(); it != _projectiles.end();){
        for (std::vector<invader>::iterator in = _invaders.begin(); in != _invaders.end();){
            if(in->contientposition(it->pos())){
                it = _projectiles.erase(it);
                in = _invaders.erase(in);
            }
        }
    }
}
