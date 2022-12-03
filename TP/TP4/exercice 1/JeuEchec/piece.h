#ifndef PIECE_H
#define PIECE_H
#include "position.h"
#include <vector>
#include <memory>

enum class couleur{
    BLANC,NOIR
};

class piece
{
private:
    std::vector<position>deplacement;
    couleur _C;
    position _P;
public:
    piece(couleur const & C, position const & P);
    bool deplacer(position const & P);
    virtual void deplacementPossibles() = 0;
    virtual unsigned short int valeur() const = 0;
    virtual char name() const = 0;
    std::string toString() const;
    couleur const & getColor() const;
    const position &P() const;
    void setP(const position &newP);
    void ajouterDeplacement(position const & p);
    void viderDeplacement();
    const std::vector<position> &getDeplacement() const;
    virtual std::unique_ptr<piece>clone() const =0;
};

#endif // PIECE_H
