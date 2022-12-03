#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <vector>

#include <bits/shared_ptr.h>
#include <bits/unique_ptr.h>

enum class type{personne, societe, couple};

// PROPRIETAIRE

class proprietaire{
public:
    virtual std::string nom()const=0;
    virtual type typeprop()const=0;//on peut le faire avec un string !
    virtual std::string adresse()const=0;
    virtual std::string etiquetteexpedition()const{return nom()+", "+adresse();}
    virtual void sortieflux(std::ostream & os)const;
    virtual ~proprietaire()=default;
    static std::shared_ptr<proprietaire>fabrique(std::string const & nom,std::string const & addr,std::string const & nais);
    static std::shared_ptr<proprietaire>fabrique(std::string const & nom,std::string const & addr,std::shared_ptr<proprietaire> p);
    static std::shared_ptr<proprietaire>fabrique(std::shared_ptr<proprietaire> p1,std::shared_ptr<proprietaire> p2);
};

std::ostream & operator<<(std::ostream & os,proprietaire const &p);
std::ostream& operator<<(std::ostream & os,type t);

// PERSONNE

class personne:public proprietaire{
public:
    std::string nom()const override{return _nom;}
    type typeprop()const override{return type::personne;}
    std::string adresse()const override{return _adresse;}
    void sortieflux(std::ostream & os)const override;

private:
    std::string _nom;
    std::string _adresse;
    std::string _naissance;
    personne(std::string const & nom,std::string const & addr,std::string const & nais):_nom(nom),_adresse(addr),_naissance(nais){}
    friend class proprietaire;
};

// SOCIETE

class societe:public proprietaire{
public:
    std::string nom()const override{return _nom;}
    type typeprop()const override{return type::societe;}
    std::string adresse()const override{return _adresse;}
    void sortieflux(std::ostream & os)const override;

private:
    societe(std::string const & nom,std::string const & addr,std::shared_ptr<personne> g):
        _nom(nom),_adresse(addr),_gerant(g){}
    std::string _nom;
    std::string _adresse;
    std::shared_ptr<personne> _gerant;
    friend class proprietaire;

};
class couple:public proprietaire{
public:
    std::string nom()const override{return _p1->nom()+" et "+_p2->nom();}
    type typeprop()const override{return type::couple;}
    std::string adresse()const override{return _p1->adresse();}
private:
    couple(std::shared_ptr<personne> p1,std::shared_ptr<personne> p2):_p1(p1),_p2(p2){}
    std::shared_ptr<personne> _p1;
    std::shared_ptr<personne> _p2;
    friend class proprietaire;
};

// ######################## COMPTE ########################

class compte {
public:
    compte(std::shared_ptr<proprietaire> p, float m);
    float montant() const;
    void setMontant(float newMontant);
    const std::shared_ptr<proprietaire> &prop() const;
    virtual ~compte() = default;
    virtual std::shared_ptr<compte>clone() const =0;
    virtual void sortieflux(std::ostream &os) const;
    void appliquerInteret();
    bool verser(float m);
    bool retirer(float m);
    bool virer(compte & dest, float m);
private:
    std::shared_ptr<proprietaire>_prop;
    float _montant;
    static unsigned int _compteur;
    int _numero;
protected:
    virtual bool montantautorise(float m) const = 0;
    virtual float taux() const = 0;
};

// COMPTE COURANT

class compteCourant : public compte {
private:
    float _decouvert;
public:
    compteCourant(const std::shared_ptr<proprietaire> &p, float m);
    void setDecouvert(float newDecouvert);
    std::shared_ptr<compte> clone() const override;
    void sortieflux(std::ostream &os) const override;
    // compte interface
protected:
    bool montantautorise(float m) const override { return m >= _decouvert; }
    float taux() const override { return 0 ;}

};

// LDD

class LDD : public compte{
private:
    static float _tauxinteret;
    LDD(const std::shared_ptr<proprietaire> &p, float m);
public:
    static std::shared_ptr<LDD>fabrique(const std::shared_ptr<proprietaire> &p, float m);
    std::shared_ptr<compte> clone() const override;
    void sortieflux(std::ostream &os) const override;
    // compte interface
    static void setTauxinteret(float newTauxinteret);
protected:
    bool montantautorise(float m) const override;
    float taux() const override { return this->_tauxinteret ;}

};

// LEP

class LEP : public compte{
private:
    LEP(const std::shared_ptr<proprietaire> &p, float m);
    static float _tauxinteret;
public:
    static std::shared_ptr<LEP>fabrique(const std::shared_ptr<proprietaire> &p, float m);
    std::shared_ptr<compte> clone() const override;
    void sortieflux(std::ostream &os) const override;
    static void setTauxinteret(float newTauxinteret);

protected:
    bool montantautorise(float m) const override;
    float taux() const override { return this->_tauxinteret ;}
};


// #################### BANQUE ##############################

class banque {
private:
    std::vector<std::shared_ptr<compte>> _comptes;
public:
    banque(){}
    banque(const banque &s) = delete;
    ~banque() = default;
    banque &operator=(const banque &s) = delete;
    void ajouter(std::shared_ptr<compte> C);
    void appliquerTauxInteret();
    void sortieflux(std::ostream &os) const;
    friend std::ostream & operator<<(std::ostream &os,banque const &B);
    std::shared_ptr<proprietaire> chercheproprietaire(std::string const & s) const;
    std::vector<int> comptes(const proprietaire &p) const;
};


/*Écrire une méthode comptes prenant comme paramètre un propriétaire et retournant l’ensemble des
identifiants des comptes de ce propriétaire. Attention, si le propriétaire est une personne physique on
veut que la méthode retourne aussi les comptes qui ont pour propriétaire un couple dans lequel est
présent la personne physique, et les sociétés dont le gérant est la personne physique en question*/





