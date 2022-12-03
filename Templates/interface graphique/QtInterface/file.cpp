#include "file.h"

// ################### SAISI QT INTERFACE ######################

maClass::maClass():QWidget()
{
    // INITIALISTATION (passage par liste d'iniatialisation donne des warning)
    _champ1 = new QLineEdit("",this);
    _champ2 = new QLineEdit("",this);
    _quitter = new QPushButton("quitter",this);
    _ajouter = new QPushButton("Ajouter",this);
    _resultat = new QLabel("",this);
    resize(1000,500);
    _champ1->setGeometry(10,10,200,50);
    _champ2->setGeometry(250,10,150,30);
    setWindowTitle("CC");
    _resultat->setGeometry(350,300,300,30);
    _quitter->setGeometry(520,10,100,30);
    _ajouter->setGeometry(260,200,100,100);
    connect(_quitter,&QPushButton::clicked,this,&maClass::close);
    connect(_ajouter,&QPushButton::clicked,this,&maClass::ajouter);
}

void maClass::ajouter()
{
    std::string nom(_champ1->text().toStdString());
    auto niveau(_champ2->text().toInt()); // INT
    _resultat->setText("<font color='black'>Information invalide</font>");
}
