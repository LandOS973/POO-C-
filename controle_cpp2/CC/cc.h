#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

// ################### HORAIRE ######################

class horaire{
private:
    unsigned int heure;
    unsigned int jour;
    unsigned int mois;
public:
    horaire(unsigned int heure, unsigned int jour, unsigned int mois);
    std::string toString() const;
    void setHeure(unsigned int newHeure);
    unsigned int getHeure() const;
    unsigned int getJour() const;
    unsigned int getMois() const;
    bool operator==(const horaire &p) const;
    bool operator!=(const horaire &p) const;
    bool operator<=(const horaire &p) const;
};

enum class unite{
    POO,Archi,DCRA
};

// ################### RDV ######################

class RDV{
public:
    friend class creneauxens;
    friend class vacances;
    friend class medical;
    virtual ~RDV() = default;
    virtual bool decaler(int h);
    virtual void sortieflux(std::ostream &os) const;
    virtual std::string type() const = 0;
    RDV(const horaire &h, int duree);
    const horaire &h() const;
    friend std::ostream & operator<<(std::ostream &os,RDV const &S);
    int getDuree() const;

private:
    horaire _h;
    int duree;
};

// ################### creanaux ens ######################

class creneauxens : public RDV{
public:
    unite getMatiere() const;
    static std::shared_ptr<creneauxens> fabrique(unite matiere, const horaire &h);
    static std::shared_ptr<creneauxens> fabrique(unite matiere, const horaire &h, int duree);
    std::string unite_toString() const;
private:
    creneauxens(unite matiere, const horaire &h);
    creneauxens(unite matiere, const horaire &h, int duree);
    unite matiere;
public:
    bool decaler(int h) override;

    // RDV interface
public:
    void sortieflux(std::ostream &os) const override;
    std::string type() const override;
};

class medical : public RDV{
public:
    const std::string &getNomMed() const;
    static std::shared_ptr<medical> fabrique(const std::string &nomMed, const horaire &h);
private:
    std::string nomMed;
    medical(const std::string &nomMed, const horaire &h);
    // RDV interface
public:
    bool decaler(int h) override;

    // RDV interface
public:
    void sortieflux(std::ostream &os) const override;
    std::string type() const override;
};

class vacances : public RDV{
private:
    vacances(const horaire &h,int duree);
public:
    static std::shared_ptr<vacances> fabrique(const horaire &h,int duree);

    // RDV interface
public:
    std::string type() const override;
};

// ################### CARNET ######################

class carnet{
private:
    std::vector<std::shared_ptr <RDV>> _contenu;
public:
    void ajouter(std::shared_ptr<RDV> p);
    std::vector<std::shared_ptr <RDV>> examencarnet(const horaire & h) const;
    void supprimermatiere(const unite & m);
    void saisimedical();
    carnet() {}
};

//#################### EXCEPTION ##########################

class exceptioncarenet : public std::exception {
private:
    std::string _msg;
    // exception interface
public:
    exceptioncarenet(const std::string &msg);
    const char *what() const noexcept override;
};

// ################### QT ######################

class qt_decaler : public QWidget{
    Q_OBJECT
private:
    QLineEdit * _champ1;
    QPushButton *_decaler;
    QPushButton *_quitter;
    QLabel *_resultat;
    QLabel *_horaire;
    QHBoxLayout *layout;
    std::shared_ptr<RDV> _R;
public:
    qt_decaler(std::shared_ptr<RDV> R);
public slots:
    void decaler();
};




