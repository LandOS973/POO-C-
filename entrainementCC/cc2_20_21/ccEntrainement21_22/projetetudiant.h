#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>

// ############################ ETUDIANT ##############################

enum class languages{
    cpp,js,php,python
};


enum class typePersonne{
    M1,M2,enseignant
};

class personnel{
private:
    std::string _nom;
public:
    ~personnel() = default;
    personnel(const std::string &nom);
    virtual typePersonne typePers() const = 0;
    virtual void sortieflux(std::ostream &os) const;
    std::string afficheTypePersonne() const;
    virtual bool expert() const = 0;
    friend std::ostream & operator<<(std::ostream &os,personnel const &S);
    const std::string &nom() const;
};

class etudiant: public personnel
{
private:
    static int count;
    int _numero;
    etudiant(const std::string &nom);
public:
    ~etudiant() = default;
    friend class etudiantM1;
    friend class etudiantM2;
    friend class universite;
    void sortieflux(std::ostream &os) const override;
};

// ETUDIANT M1

class etudiantM1 : public etudiant{
private:
    std::vector<languages>_languages;
    etudiantM1(const std::vector<languages> &languages, const std::string &nom);
public:
    friend class universite;
    static std::shared_ptr<etudiantM1>fabrique(const std::vector<languages> &languages, const std::string &nom);
    typePersonne typePers() const override;
    bool maitriselangage(const languages & l) const;
    void sortieflux(std::ostream &os) const override;
    bool expert() const override;
};

// ETUDIANT M2

class etudiantM2 : public etudiant{
private:
    etudiantM2(int niveauExpertise, const std::string &nom);
    int _niveauExpertise;
public:
    friend class universite;
    static std::shared_ptr<etudiantM2>fabrique(int niveauExpertise, const std::string &nom);
    typePersonne typePers() const override;
    bool expert() const override;
};

// ENSEIGNANT

class enseignant : public personnel{
public:
    enseignant(int numBureau, const std::string &nom);
private:
    int _numBureau;
    typePersonne typePers() const override;
    bool expert() const override;
};

// ############## EXCEPTION ##########################

class exceptionuniversite : public std::exception{
    std::string _msg;
    // exception interface
public:
    exceptionuniversite(const std::string &msg);
    const char *what() const noexcept override;
};

// ################## PROJET ###########################


class projet{
private:
    std::vector<std::shared_ptr <personnel>> _participants;
public:
    void ajout(std::shared_ptr<personnel>p);

};

// ################### UNVIERSITE ######################

class universite{
public:
    universite() {}
    bool ajout(std::shared_ptr<personnel>p);
    void ajout(projet const &P);
    std::vector<std::shared_ptr<etudiantM1> > rechercherdevs(languages const & l)const;
    void saisiem2();
private:
    std::vector<std::shared_ptr <personnel>> _personnes;
    std::vector<projet> _ensembleDeProjet;
    friend std::ostream & operator<<(std::ostream &os,universite const &S);
};


// ################### QT ######################

class saisiem2qt : public QWidget{
    Q_OBJECT
private:
    universite _U;
    QLineEdit * _niveauexpertise;
    QLineEdit * _nom;
    QPushButton *_ajouter;
    QPushButton *_quitter;
    QLabel *_resultat;
public:
    saisiem2qt(universite const &U);
public slots:
    void ajouter();
};



