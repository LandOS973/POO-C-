#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>
#include <string>



class document
{
private:
    std::string nomAuteur;
    std::string titre;
public:
    document(const std::string &nomAuteur, const std::string &titre);
    virtual ~document() = default;
    virtual float cout() const = 0;
    virtual bool empruntable() const = 0;
    virtual void sortie(std::ostream & os) const;
    virtual std::string type() const = 0;
    friend std::ostream & operator<<(std::ostream &os,document const &S);
    virtual document * clone() const = 0;
};

#endif // DOCUMENT_H
