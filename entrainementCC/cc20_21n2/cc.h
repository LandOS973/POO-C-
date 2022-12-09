#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#pragma once

// ################### PERSONNE ######################

enum class typersonne{
    M1,M2,enseignant
};

class personne{
public:
    personne(const std::string &nom);
    virtual typersonne typepers() const = 0;
    virtual ~personne() = default;
    virtual void sortieflux(std::ostream &os) const;
    std::string retourneType() const;
    virtual bool expert() const = 0;
    friend std::ostream & operator<<(std::ostream &os,personne const &S);
    const std::string &nom() const;
private:
    std::string _nom;
};

// ################### ETUDIANT ######################

class etudiant : public personne {
public:
    virtual ~etudiant() = default;
    etudiant(const std::string &nom);
private:
    static int count;
    int _numero;

    // personne interface
public:
    void sortieflux(std::ostream &os) const override;
};

// ################### M1 ######################

enum class langages{
    cpp,js,php,python
};

class M1 : public etudiant {
private:
    M1(const std::vector<langages> &langages, const std::string &nom);
    std::vector<langages>_langages;
public:
    static std::shared_ptr<M1> fabrique(const std::vector<langages> &langages, const std::string &nom);
    typersonne typepers() const override;
    bool maitriselangage(const langages & L) const;
    void sortieflux(std::ostream &os) const override;
    bool expert() const override;
};

// ################### M2 ######################

class M2 : public etudiant {
private:
    M2(int niveau, const std::string &nom);
    int _niveau;
public:
    static std::shared_ptr<M2> fabrique(int niveau, const std::string &nom);
    typersonne typepers() const override;
    void sortieflux(std::ostream &os) const override;
    bool expert() const override;
};

// ################### ENSEIGNANT ######################

class ensegiant : public personne {
private:
    int _numBureau;
public:
    ensegiant(int numBureau, const std::string &nom);
    typersonne typepers() const override;
    void sortieflux(std::ostream &os) const override;
    bool expert() const override;
};

//#################### EXCEPTION ##########################

class exceptionuniversite : public std::exception {
private:
    std::string _msg;
    // exception interface
public:
    exceptionuniversite(const std::string &msg);
    const char *what() const noexcept override;
};

// ################### PROJET ######################

class projet{
private:
    std::vector<std::shared_ptr <personne>> _personnes;
public:
    void ajouter(std::shared_ptr<personne> p);
};

// ################### UNIVERSITE ######################

class unversite {
private:
    std::vector<std::shared_ptr <personne>> _personnes;
    std::vector<projet> _projets;
public:
    void ajouter(std::shared_ptr<personne> p);
    void ajouter(const projet &p);
    std::vector<std::shared_ptr <personne>> rechercherdevs(const langages l) const;

};

// ################### QT ######################

class saisi : public QWidget{
    Q_OBJECT
private:
    QLineEdit * _champ1;
    QLineEdit * _champ2;
    QPushButton *_ajouter;
    QPushButton *_quitter;
    QLabel *_resultat;
    QHBoxLayout *layout;
    unversite _U;

public:
    saisi(unversite const &U);
public slots:
    void ajouter();
};


















