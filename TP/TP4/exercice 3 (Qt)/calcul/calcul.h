#ifndef CALCUL_H
#define CALCUL_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>

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

class calcul : public QWidget
{
Q_OBJECT
private:
    QLineEdit *_operande1;
    QLineEdit *_operande2;
    QPushButton *_calculer;
    QPushButton *_quitter;
    QLabel *_resultat;
    QComboBox *_operateur;
public:
    calcul();
public slots:
    void oncliccalculer();

};

#endif // CALCUL_H
