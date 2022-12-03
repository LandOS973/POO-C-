#ifndef TAILLEPOSITION_H
#define TAILLEPOSITION_H

using coordonnee = int;

class position{
private:
    coordonnee _x;
    coordonnee _y;
public:
    position(coordonnee x, coordonnee y);
    position(position const & P);
    coordonnee const & get_x() const;
    void set_x(coordonnee const x);
    coordonnee const & get_y() const;
    void set_y(coordonnee const y);
    bool comparaison(position const & P) const;
    ~position();
};

class taille{
private:
    coordonnee _largeur;
    coordonnee _hauteur;
public:
    taille(coordonnee largeur, coordonnee hauteur);
    ~taille();
    void set_largeur(coordonnee const largeur);
    void set_hauteur(coordonnee const hauteur);
    coordonnee const & get_largeur() const;
    coordonnee const & get_hauteur() const;
};

#endif // TAILLEPOSITION_H
