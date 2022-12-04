#include <string>
#include <iostream>
#include <vector>
#include <memory>

#pragma once

class groupe
{
private:
    int _annee;
    std::string _nom;
    static int count;
    int _numero;
public:
    groupe(int annee, const std::string &nom);
    bool operator ==(const groupe &g)const;
    int annee() const;
    const std::string &nom() const;
    int numero() const;
};

// ################### ELEMENT ######################


class element
{
private:
    unsigned int importance;
public:
    element(unsigned int importance);
    virtual ~element() = default;
    friend class fichier;
    friend class page;
    friend class devoir;
    virtual void sortieflux(std::ostream &os) const;
    virtual std::unique_ptr<element>clone() const = 0;
    friend std::ostream & operator<<(std::ostream &os,element const &S);
    unsigned int getImportance() const;
    void setImportance(unsigned int newImportance);
    friend class devoir;
};

// ################### FICHER ######################

class fichier : public element
{
private:
    std::string _url;
public:
    fichier(const std::string &url);
    void sortieflux(std::ostream &os) const override;
    std::unique_ptr<element> clone() const override;
};

struct section{
    std::string contenu;
    bool visible;
};

// ################### PAGE ######################

class page : public element
{
public:
    void ajouterSection(section const & s);
    void sortieflux(std::ostream &os) const override;
    std::unique_ptr<element> clone() const override;
    static std::shared_ptr<page> fabrique(int importance);
private:
    page(int importance);
    std::vector<section>_section;
};

// ################### DEVOIR ######################

struct rendu
{
    std::string nom;
    std::string contenu;
};

class devoir : public element
{
private:
    std::shared_ptr<element> _e;
    rendu _rendu;
public:
    devoir(std::shared_ptr<element> e);
    devoir(const devoir &d);
    void ajouterRendu(rendu const & r);
    void sortieflux(std::ostream &os) const override;
    std::unique_ptr<element> clone() const override;
};

// ################### ESPACE ######################

class espace{
public:
    std::string _nom;
    std::vector<std::unique_ptr <element>> _elements;
    std::vector<groupe> _groupes;
    static int count;
    int _numero;
    static std::shared_ptr<espace>fabrique(std::string const & nom);
    void ajoutergroupe(const groupe &g);
    void ajouterelement(std::unique_ptr <element> e);
    espace &operator=(const espace &s);
    espace(const espace &s);
    friend std::ostream & operator<<(std::ostream &os,espace const &S);
private:
    espace(std::string const & nom);

};











