#include "file.h"

// ################### SAISI QT INTERFACE ######################

maClass::maClass():QWidget()
{
    // INITIALISTATION (passage par liste d'iniatialisation donne des warning)
    layout = new QHBoxLayout(window());
    _champ1 = new QLineEdit("",this);
    _champ2 = new QLineEdit("",this);
    _quitter = new QPushButton("quitter",this);
    _ajouter = new QPushButton("Ajouter",this);
    _resultat = new QLabel("",this);
    layout->addWidget(_champ1);
    layout->addWidget(_champ2);
    layout->addWidget(_ajouter);
    layout->addWidget(_quitter);
    layout->addWidget(_resultat);
    setWindowTitle("CC");
    connect(_quitter,&QPushButton::clicked,this,&maClass::close);
    connect(_ajouter,&QPushButton::clicked,this,&maClass::ajouter);
}

void maClass::ajouter()
{
    std::string nom(_champ1->text().toStdString());
    auto niveau(_champ2->text().toInt()); // INT
    _resultat->setText("<font color='black'>Information invalide</font>");
}
