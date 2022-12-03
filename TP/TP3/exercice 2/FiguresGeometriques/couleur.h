#ifndef COULEUR_H
#define COULEUR_H

class couleur
{
private:
    unsigned short int _rouge;
    unsigned short int _bleu;
    unsigned short int _vert;
public:
    couleur(unsigned short int rouge, unsigned short int bleu,unsigned short int vert):_rouge(rouge), _bleu(bleu), _vert(vert){}
    unsigned short int const & getRouge() const { return _rouge; }
    unsigned short int const & getBleu() const { return _bleu; }
    unsigned short int const & getVert() const { return _vert; }
    void setBleu(unsigned short int bleu) { _bleu = bleu; }
    void setRouge(unsigned short int rouge) { _rouge = rouge; }
    void setVert(unsigned short int vert) { _vert = vert; }
};

#endif // COULEUR_H
