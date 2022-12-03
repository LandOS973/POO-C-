#ifndef ECHEQUIER_H
#define ECHEQUIER_H
#include <memory>
#include "piece.h"

class echequier
{
private:
    std::vector<std::unique_ptr<piece>> _plateau;
private:
    void ajouterPiece(std::unique_ptr<piece> p);
public:
    /*. Écrire une méthode sauvegarde prenant comme paramètre un std::ofstream et écrivant dans le
flux fichier la totalité des pièces sous la forme retournée par tostring, une pièce par ligne.*/
    echequier();
    echequier(echequier const & e);
    echequier &operator=(const echequier &e);
    ~echequier() = default;
    void afficherNoir(std::ostream &os) const;
    void afficherBlanc(std::ostream &os) const;
    int valeurDuJoueur(const couleur &c) const;
    void sauvegarde(std::ofstream &f) const;
    bool deplacer(const position &source,const position &destination);
    void chargement(std::ifstream & os);
};

#endif // ECHEQUIER_H
