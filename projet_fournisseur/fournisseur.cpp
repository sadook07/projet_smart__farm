#include "fournisseur.h"
#include <QString>
#include <QSqlQueryModel>

#include <QSqlQuery>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <iostream>
#include <QMessageBox>

using namespace std;


fournisseur::fournisseur()
{
     ID_F=0 ;nom="";  prenom=""; addresse="";numero=0;


}


fournisseur::fournisseur(QString nom,QString prenom,int numero,QString addresse)

{


   this-> nom=nom;
   this-> prenom=prenom;
     this-> addresse=addresse;
     this-> numero=numero;


    }
fournisseur::fournisseur(int id,QString nom,QString prenom,int numero,QString addresse)

{

 this->ID_F=id;
   this-> nom=nom;
   this-> prenom=prenom;
     this-> addresse=addresse;
     this-> numero=numero;


    }
fournisseur::fournisseur(int id)

{

 this->ID_F=id;



    }


bool fournisseur::ajouter()
{
    QSqlQuery query;


    query.prepare("INSERT INTO FOUR (ID_F,NOM, PRENOM, NUMERO, ADDRESSE) VALUES (:ID_F,:nom, :prenom, :numero, :addresse)");

    query.bindValue(":ID_F",ID_F);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":numero", numero);
    query.bindValue(":addresse", addresse);


return query.exec();
}
bool fournisseur::supprimer()
{
    QSqlQuery query;
    QString num=QString::number(ID_F);

    query.prepare("DELETE FROM FOUR WHERE ID_F=:ID_F");
 query.bindValue(":ID_F",num);
    return query.exec();
}
QSqlQueryModel * fournisseur::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("Select * from FOUR ");
    model->setHeaderData(0,Qt::Horizontal,"ID_F");
    model->setHeaderData(1,Qt::Horizontal,"NOM");
    model->setHeaderData(2,Qt::Horizontal,"PRENOM");
    model->setHeaderData(3,Qt::Horizontal,"NUMERO");
    model->setHeaderData(4,Qt::Horizontal,"ADDRESSE");

    return model ;
   // QTableView *tableau = new QTableView;
    //tableau->setModel(model);
}
bool fournisseur ::modifer()
{
    QSqlQuery query;
    query.prepare("UPDATE  four SET ID_F=:ID_F,NOM=:NOM,PRENOM=:PRENOM,NUMERO=:NUMERO,ADDRESSE=:ADDRESSE where ID_F=:ID_F");
    query.bindValue(":ID_F",ID_F);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
     query.bindValue(":NUMERO",numero);
      query.bindValue(":ADDRESSE",addresse);

    return query.exec();
}


