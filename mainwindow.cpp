#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPalette>
#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "associations.h"


#include <QMessageBox>
#include <QIntValidator>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QSqlQuery>
#include<QPixmap>
#include<QListWidget>
#include <QPdfWriter>
#include <QFile>
#include <QCoreApplication>
#include <QDesktopServices>

#include <QSqlQuery>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->icon_only->setVisible(false);

 ui->lineEdit_idDon->setValidator( new QIntValidator(0, 9999, this));
 ui->lineEdit_montant->setValidator( new QIntValidator(0, 99999999999999, this));
 ui->lineEdit_idOeuvre->setValidator( new QIntValidator(0, 9999, this));
QRegularExpression rx("[A-Za-z]+");
QValidator *stringValidator = new QRegularExpressionValidator(rx, this);
ui->lineEdit_type ->setValidator(stringValidator);

QRegularExpression f("[A-Z][a-zA-Z]*"); // Regular expression to match string with first character uppercase and rest alphabetic
   QValidator *stringValidatorf = new QRegularExpressionValidator(f, this);
   ui->lineEdit_destinataire ->setValidator(stringValidatorf);


    QPixmap backgroundImage("C:/Users/USER/OneDrive/Bureau/icons/Put your demo inside here");
    setAutoFillBackground(true);
       QPalette palette;
       palette.setBrush(QPalette::Background, backgroundImage);
       setPalette(palette);
       //CustomWidget*customWidget = new CustomWidget(this);
      // setCentralWidget(customWidget);
    connect(ui->menu, &QPushButton::clicked, this, &MainWindow::toggleIconOnlyWidget);
    connect(ui->file, &QPushButton::clicked, this, &MainWindow::navigateToPage);
    connect(ui->file2, &QPushButton::clicked, this, &MainWindow::navigateToPage);
    connect(ui->view, &QPushButton::clicked, this, &MainWindow::navigateToPage);
    connect(ui->view2, &QPushButton::clicked, this, &MainWindow::navigateToPage);
    connect(ui->edit, &QPushButton::clicked, this, &MainWindow::navigateToPage);
    connect(ui->edit2, &QPushButton::clicked, this, &MainWindow::navigateToPage);
    connect(ui->tools, &QPushButton::clicked, this, &MainWindow::navigateToPage);
    connect(ui->tools2, &QPushButton::clicked, this, &MainWindow::navigateToPage);
    connect(ui->help, &QPushButton::clicked, this, &MainWindow::navigateToPage);
    connect(ui->help2, &QPushButton::clicked, this, &MainWindow::navigateToPage);
    connect(ui->users, &QPushButton::clicked, this, &MainWindow::navigateToPage);
    connect(ui->users2, &QPushButton::clicked, this, &MainWindow::navigateToPage);
    ui->file->setProperty("PageIndex", 0);  // Associate page index directly with the button
    ui->file2->setProperty("PageIndex", 0);  // Associate page index directly with the button
    ui->view->setProperty("PageIndex", 1);
    ui->view2->setProperty("PageIndex", 1);
    ui->edit->setProperty("PageIndex", 2);
    ui->edit2->setProperty("PageIndex", 2);
    ui->tools->setProperty("PageIndex", 3);// Associate page index directly with the button
    ui->tools2->setProperty("PageIndex", 3);
    ui->help->setProperty("PageIndex", 4);
    ui->help2->setProperty("PageIndex", 4);
    ui->users->setProperty("PageIndex", 5);
    ui->users2->setProperty("PageIndex", 5);

       // Refresh the widget
    ui->tableView->setModel(E.afficher());

}
void MainWindow::toggleIconOnlyWidget()
{
    bool isVisible = ui->icon_only->isVisible();
    ui->icon_only->setVisible(!isVisible);
    ui->full_menu->setVisible(isVisible); // Show icon_name_widget when icon_only_widget is hidden
}

int MainWindow::findPageIndex(const QPushButton *button) const
{
    return button->property("PageIndex").toInt();
}

void MainWindow::navigateToPage()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

    if (clickedButton) {
        // Find the index of the page
        int pageIndex = findPageIndex(clickedButton);

        // Switch to the corresponding page in the stackedWidget
        if (pageIndex >= 0) {
            ui->icon_only->setVisible(true);
            ui->full_menu->setVisible(false);
            ui->stackedWidget->setCurrentIndex(pageIndex);
        }
    }
}



/*void MainWindow::afficherAssociations()
{
    associations assoc;
    QSqlQueryModel *model = assoc.afficher();
    ui->tableView->setModel(model);
}*/


void MainWindow::on_pushButton_ajouter_clicked()
{int idDon = ui->lineEdit_idDon->text().toInt();
    QString type = ui->lineEdit_type->text();
    QString destinataire = ui->lineEdit_destinataire->text();
    float montant = ui->lineEdit_montant->text().toFloat();
    int idOeuvre = ui->lineEdit_idOeuvre->text().toInt();
associations assoc(idDon,type,destinataire,montant,idOeuvre);
    if(assoc.ajouter()) {
           QMessageBox::information(this, "Succès", "Association ajoutée avec succès.");
           // Réafficher la liste après l'ajout
           //assoc.afficher();+
           ui->tableView->setModel(E.afficher());

       } else {
           QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de l'association.");
       }

}
/*void MainWindow::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_idASupprimer->text().toInt();
    associations assoc;
    if(assoc.supprimer(id)) {
        ui->statusBar->showMessage("Association supprimée avec succès.");
        // Réafficher la liste après la suppression
        assoc.afficher();
    } else {
        ui->statusBar->showMessage("Erreur lors de la suppression de l'association.");
    }
}

void MainWindow::on_pushButton_modifier_clicked()
{
    associations assoc;
    if(assoc.modifier()) {
        ui->statusBar->showMessage("Association modifiée avec succès.");
        // Réafficher la liste après la modification
        assoc.afficher();
    } else {
        ui->statusBar->showMessage("Erreur lors de la modification de l'association.");
    }
}*/
MainWindow::~MainWindow()
{
    delete ui;
}






 /*   int idDon = ui->lineEdit_2->text().toInt();
        QString type = ui->type->text();
        QString destinataire = ui->ress->text();
        float montant = ui->price->text().toFloat();
        int idOeuvre = ui->idou->text().toInt();

            associations assoc(idDon,type,destinataire,montant,idOeuvre);
       bool test=E.modifier(idDon);


       if(test)
    {

                QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("update successful.\n"
                                        "update effectuer."), QMessageBox::Cancel);
                ui->tableView->setModel(E.afficher());



    }
            else

                QMessageBox::critical(nullptr, QObject::tr("nope"),
                            QObject::tr("connection failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }

*/
void MainWindow::on_supprimer_clicked()
{

    associations E1;
    E1.setIdDon((ui->lineEdit_2->text().toInt()));
        bool test=E1.supprimer(E1.getIdDon());

        QMessageBox msgBox;
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("Suppression effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_2->setModel(E.afficher());
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("Suppression non  effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_modifier_clicked()
{
    int idDon = ui->lineEdit_2->text().toInt();
        QString type = ui->type->text();
        QString destinataire = ui->ress->text();
        float montant = ui->price->text().toFloat();
        int idOeuvre = ui->idou->text().toInt();
    associations assoc(idDon,type,destinataire,montant,idOeuvre);
    bool test=assoc.mod(idDon);
    if(test)
       {

                   QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("update successful.\n"
                                           "update effectuer."), QMessageBox::Cancel);
                   ui->tableView_2->setModel(E.afficher());



       }
               else

                   QMessageBox::critical(nullptr, QObject::tr("nope"),
                               QObject::tr("connection failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
           }




void MainWindow::on_afficher_clicked()
{
      ui->tableView_2->setModel(E.afficher());

}

void MainWindow::on_view_2_clicked()
{
    ui->tableView->setModel(E.afficher());


}

void MainWindow::on_pushButton_2_clicked()
{
    QPdfWriter pdf("C:/Users/USER/OneDrive/Bureau/ASSOCIATIONS.pdf");

              QPainter painter(&pdf);
              int i = 4000;
                     painter.setPen(Qt::darkCyan);
                     painter.setFont(QFont("Time New Roman", 25));
                     painter.drawText(3000,1400,"ASSOCIATIONS");
                     painter.setPen(Qt::black);
                     painter.setFont(QFont("Time New Roman", 15));
                     painter.drawRect(100,100,9400,2500);
                     painter.drawRect(100,3000,9400,500);
                     painter.setFont(QFont("Time New Roman", 9));
                     painter.drawText(4400,3300," IDDON");
                     painter.drawText(400,3300,"TYPE");
                     painter.drawText(1350,3300,"DES");
                     painter.drawText(2200,3300,"MONT");
                     painter.drawText(3400,3300,"OV");


                     painter.drawRect(100,3000,9400,9000);

                     QSqlQuery query;
                     query.prepare("select * from ASSOCIATIONS");
                     query.exec();
                     while (query.next())
                     {

                         painter.drawText(1350,i,query.value(1).toString());
                         painter.drawText(2300,i,query.value(2).toString());
                         painter.drawText(3400,i,query.value(3).toString());
                         painter.drawText(4400,i,query.value(4).toString());
                         painter.drawText(6200,i,query.value(5).toString());
                         painter.drawText(6200,i,query.value(6).toString());




                        i = i + 350;
                     }
                     QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                     QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_Boutton_rechecher_clicked()
{
   int idDon = ui->la_chercher_id->text().toInt();
        ui->tableView->setModel(E.chercher_id(idDon));
}
