#ifndef FILE_H
#define FILE_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>


// ################### QT ######################

class maClass : public QWidget{
    Q_OBJECT
private:
    QLineEdit * _champ1;
    QLineEdit * _champ2;
    QPushButton *_ajouter;
    QPushButton *_quitter;
    QLabel *_resultat;
    QHBoxLayout *layout;
public:
    maClass();
public slots:
    void ajouter();
};

#endif // FILE_H
