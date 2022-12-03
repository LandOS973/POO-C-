#ifndef TAILLE_H
#define TAILLE_H


class taille
{
private:
    unsigned int _h;
    unsigned int _w;
public:
    taille(unsigned int h, unsigned int w);


    unsigned int h() const;
    unsigned int w() const;
    void setW(unsigned int newW);
};

#endif // TAILLE_H
