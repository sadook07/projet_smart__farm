#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "fournisseur.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
          int id=ui->lineEdit_5->text().toInt();
          QString nom=ui->lineEdit->text();
           QString prenom=ui->lineEdit_2->text();
            int numero=ui->lineEdit_3->text().toInt();
             QString addresse=ui->lineEdit_4->text();


                fournisseur f(id,nom,prenom,numero,addresse);
                bool test1 = f.ajouter();
                if (test1)
                {
                    ui->tableau->setModel(f.afficher());//refresh



                    QMessageBox::information(nullptr,"AJOUT Fourniseur","Fourniseur AJOUTEE");
                }
                else
                {
                    QMessageBox::warning(nullptr,"AJOUT Fourniseur","Fourniseur non AJOUTEE");
                }

}

void MainWindow::on_pushButton_2_clicked()
{
    int ID_A =ui->lineEdit_5->text().toInt();
       fournisseur f (ID_A);
        bool test =f.supprimer();
        if (test)
        {

         f.afficher();

           QMessageBox::information(nullptr, QObject::tr("CORRECT !"),
                       QObject::tr("delete sucessful \n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else

           QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                       QObject::tr("delete failed \n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{
    int ID_F=ui->lineEdit_5->text().toInt();
    QString nom=ui->lineEdit->text();
     QString prenom=ui->lineEdit_2->text();
      int numero=ui->lineEdit_3->text().toInt();
       QString addresse=ui->lineEdit_4->text();

               fournisseur a(ID_F,nom,prenom,numero,addresse);
               bool test1 = a.modifer();
               if (test1)
               {

                   ui->tableau->setModel(a.afficher());

                   QMessageBox::information(nullptr,"Modifier fourniseur"," fourniseur modifier");
               }
               else
               {
                   QMessageBox::warning(nullptr,"Modifier  fourniseur"," fourniseur non modifier");
               }
}
