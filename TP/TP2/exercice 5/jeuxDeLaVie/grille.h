#ifndef GRILLE_H
#define GRILLE_H
#include <iostream>
#include <vector>

enum class etatcellule{
    vivante, morte
};


/*structure définissant 4 symboles pour ces structures : oscillateurligne,
floraison, planeur, oscillateurcroix. Écrire une méthode ajouterstructure dans grille*/
enum class symbole{
    oscillateurligne,floraison,planeur,oscillateur
};

class grille
{
private:
    std::size_t _largeur;
    std::size_t _hauteur;
    std::vector<std::vector<etatcellule>> _matrice;
public:
    grille(size_t largeur, size_t hauteur);
    void afficher() const;
    void vider();
    bool vivante(int x, int y) const;
    void generer(int x, int y);
    void tuer(int x, int y);
    void ajouterStructure(symbole const & S, int x, int y);
    signed int vivantes(signed int x, signed int y) const;
    void evolution(grille const & G);
    void voirEvolution(grille const & G);
};

#endif // GRILLE_H
