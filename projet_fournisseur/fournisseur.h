#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QSqlDatabase>
#include "ui_mainwindow.h"


class fournisseur


{
    int ID_F;
    QString nom;
    QString prenom;
    int numero;
    QString addresse;
public:
    fournisseur();
     fournisseur(int);
    fournisseur(int,QString,QString,int,QString);
     fournisseur(QString,QString,int,QString);
     int getID_F(){return ID_F;}
     void setID_F(int a){ID_F=a;}
      bool ajouter();
      bool supprimer();
      QSqlQueryModel * afficher();
       bool modifer();
};

#endif // FOURNISSEUR_H
