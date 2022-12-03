#ifndef JEU_H
#define JEU_H
#include "objet.h"
#include "invader.h"
#include "projectile.h"
#include "joueur.h"
#include <vector>

class jeu
{
private:
    std::vector<projectile> _projectiles;
    std::vector<invader> _invaders;
    joueur _J;
public:
    jeu();
    bool ajouter(const projectile &p);
    void ajouter(const invader &i);
    void tirjoueur();
    void tourdejeu();
    void afficherjeu()const;
private: //method
    void projectiledisparition();
    void projectilecolision();
};

#endif // JEU_H
