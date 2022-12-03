#include "calcul.h"
#include <math.h>

/*Déclarer une classe calcul, sous classe de QWidget1
 formée des attributs dont les noms et types
suivent : _operande1 (QLineEdit), _operande2 (QLineEdit), _operateur (QComboBox), _resultat
(QLabel), _calculer (QPushButton), _quitter (QPushButton). Le constructeur de QComboBox
construit un widget vide, et il faut appeler addItem pour rajouter les éléments, vous ajouterez 4
éléments à _operateur : + , - , * , / et vous positionnerez les widgets dans la fenêtre calcul (de taille
450 sur 50) pour obtenir l’apparence ci-contre (peu importe si ce n’est pas « harmonieux », si les
widgets sont trop « hauts », on
fera plus tard des « layouts »
plus propres).*/

calcul::calcul():QWidget(),
    _operande1(new QLineEdit("",this)),
    _operande2(new QLineEdit("",this)),
    _operateur(new QComboBox(this)),
    _resultat(new QLabel("",this)),
    _calculer(new QPushButton("=",this)),
    _quitter(new QPushButton("quitter",this))
{
    resize(650,100);
    _operande1->setGeometry(10,10,70,30);
    _operande2->setGeometry(180,10,70,30);
    _operateur->setGeometry(90,10,70,30);
    _operateur->addItem("+");
    _operateur->addItem("-");
    _operateur->addItem("*");
    _operateur->addItem("/");
    _resultat->setGeometry(350,10,100,30);
    _quitter->setGeometry(520,10,100,30);
    _calculer->setGeometry(260,10,70,30);
    setWindowTitle("Calculatrice");
    connect(_quitter,&QPushButton::clicked,this,&calcul::close);
    connect(_calculer,&QPushButton::clicked,this,&calcul::oncliccalculer);
    connect(_operateur,&QComboBox::currentTextChanged,this,&calcul::oncliccalculer);
    connect(_operande1,&QLineEdit::textChanged,this,&calcul::oncliccalculer);
    connect(_operande2,&QLineEdit::textChanged,this,&calcul::oncliccalculer);
}

void calcul::oncliccalculer()
{
    _resultat->setText(QString("hi"));
    auto s1(_operande1->text().toStdString());
    auto s2(_operande2->text().toStdString());
    float f1(!s1.empty() ? std::stof(s1) : 0.0);
    float f2(!s2.empty() ? std::stof(s2) : 0.0);
    float r(0.0);
    switch (_operateur->currentText().toStdString().at(0)) {
        case '+': r = f1 + f2; break;
        case '*': r = f1 * f2; break;
        case '-': r = f1 - f2; break;
        case '/': f2 == 0 ? r = 0 : r = f1 / f2; break;
        default: break;
    }
    r = ceil(r*100)/100;
    _resultat->setText("<font color='black'>"+QString::fromStdString(std::to_string(r)) +"</font>");
}
