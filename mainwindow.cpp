#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPalette>
#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "associations.h"

#include <QDebug>
//#include <QtCharts>

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
#include "smtp.h"
#include <QSqlQuery>
#include "notification.h"
#include <QSound>

#include <QTextDocument>
#include <QTextTable>
#include <QTextCursor>
#include <QDebug>





#include <QMessageBox>
#include <QDate>
#include <QRegularExpression>
#include <QUuid>
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QTextStream>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QSqlRecord>

#include <QSqlError>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QPainter>


#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
//////////////////////////
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->comboBox, SIGNAL(currentTextChanged(const QString&)), this, SLOT(on_comboBox_currentTextChanged(const QString&)));
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


/*void MainWindow::on_pushButton_ajouter_clicked()
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

}*/
void MainWindow::on_pushButton_ajouter_clicked()



{
    QSound *sound = new QSound("C:/Users/USER/OneDrive/Documents/chart/media/button.wav"); // Replace "click.wav" with the actual sound file path
       sound->play();

int idDon = ui->lineEdit_idDon->text().toInt();
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

  notif.notifAjouterMateriels();
    ui->lineEdit_idDon->clear();
    ui->lineEdit_type->clear();
   // ui->comboBox_etat->clear();
    ui->lineEdit_montant->clear();
     ui->lineEdit_idOeuvre->clear();
ui->lineEdit_destinataire->clear();

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
          notif.notifSupprimerMatereils();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("Suppression non  effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_modifier_clicked()
{

    QSound *sound = new QSound("C:/Users/USER/OneDrive/Documents/chart/media/button.wav"); // Replace "click.wav" with the actual sound file path
       sound->play();

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
                   notif.notifModifierMateriels();



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



/*void MainWindow::on_Boutton_rechecher_clicked()
{
   int idDon = ui->la_chercher_id->text().toInt();
        ui->tableView->setModel(E.chercher_id(idDon));
}*/

void MainWindow::on_comboBox_currentTextChanged(const QString &text)
{
    QString searchText = ui->la_chercher_id->text(); // Get the search text from the line edit

    if (text == "ID_Don") {
        bool ok;
        int idDon = searchText.toInt(&ok); // Convert the search text to an integer
        if (ok) {
            ui->tableView->setModel(E.chercher_id(idDon)); // Call the function to search by ID
        } else {
            qDebug() << "Invalid ID entered.";
            // Optionally, you can display an error message to the user
        }
    } else if (text == "recipient") {
        ui->tableView->setModel(E.chercher_destinataire(searchText)); // Call the function to search by recipient
    } else if (text == "type") {
        ui->tableView->setModel(E.chercher_type(searchText)); // Call the function to search by type
    } else {
        qDebug() << "Unsupported search option:" << text;
        // Optionally, you can display an error message to the user
    }
}



void MainWindow::on_sort_clicked()
{
    ui->tab->setModel(E.tri_montant());
}



/*void MainWindow::on_stat_clicked()
{

        float totalDon = E.getTotalDonationsAmount();

        // Vérifier si le montant total est valide
        if (totalDon >= 0.0f) {
            // Configuration de la valeur maximale de la barre de progression
            float montantMaxTotal = 1000000.0f; // Par exemple, un million de dollars
            ui->progressBar->setMaximum(100); // ou toute autre valeur appropriée
            // Conversion du montant total en pourcentage pour la barre de progression
            int pourcentage = static_cast<int>((totalDon / montantMaxTotal) * 100); // Utilisation de la valeur maximale définie
            // Mise à jour de la valeur de la barre de progression
            ui->progressBar->setValue(pourcentage);
        } else {
            // Gestion de l'erreur lors de l'obtention du montant total
            QMessageBox::critical(this, "Erreur", "Impossible d'obtenir le montant total des dons.");
        }
    }*/
void MainWindow::on_stat_clicked() {
    // Retrieve all donation amounts from the database
    QList<float> donationAmounts = E.getAllDonationsAmounts();

    // Calculate the total sum of donations
    float totalDon = std::accumulate(donationAmounts.begin(), donationAmounts.end(), 0.0f);

    // Configure the maximum value of the progress bar
    const float montantMaxTotal = 1000000.0f; // For example, one million dollars
    const int maxProgressBarValue = 100; // Maximum value for the progress bar

    // Calculate the percentage of total donations relative to the maximum total amount
    int pourcentage = static_cast<int>((totalDon / montantMaxTotal) * maxProgressBarValue);

    // Ensure the percentage is within the valid range [0, 100]
    if (pourcentage < 0) {
        pourcentage = 0;
    } else if (pourcentage > maxProgressBarValue) {
        pourcentage = maxProgressBarValue;
    }

    // Update the value of the progress bar
    ui->progressBar->setValue(pourcentage);
}








/*void MainWindow::on_on_send_email_clicked()
{
    // Retrieve information from QLineEdit widgets
    QString emailAddress = ui->email->text();
    QString subject = ui->sujet->text();
    QString body = ui->objet->text();

    // Check for empty fields
    if (emailAddress.isEmpty() || subject.isEmpty() || body.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs avant d'envoyer l'email.");
        return;
    }

    // Create an instance of the Smtp class
    Smtp* smtp = new Smtp("said.doghri@esprit.tn", "221JMT7702", "smtp.gmail.com", 465);

    // Compose the email
    QStringList attachments;  // Add file paths if you have attachments

    // Set the sender and recipient email addresses
    QString senderEmail = "said.doghri@esprit.tn";  // Replace with your sender email
    QString senderName = "said";
    QString recipientEmail = emailAddress;
    QString recipientName = "entreprise";

    // Set the email subject and body
    QString emailSubject = subject;
    QString emailBody = body;

    // Connect the status signal to a lambda function
    connect(smtp, &Smtp::status, [this](QString status) {
        // Disconnect the status signal
        QObject::disconnect(sender(), SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    });

    // Send the email
    smtp->sendMail(senderEmail, recipientEmail, emailSubject, emailBody, attachments);
    //QMessageBox::information(this, "Email réussie", "Email envoyé.");

}*/


void MainWindow::on_don_clicked() {
    associations E;

        associations chahed = E.getHighestDonation();
        chahed=E.getHighestDonation();
        int newsuivi=chahed.getMontant();

            QString newsuivi_string=QString::number(newsuivi);
            QString m="L'don du mois est  " +  newsuivi_string + " with Destinataire   " + chahed.getDestinataire()  +"  "+"\n"+ "!   this type of donnation wins a free membership for our next event" +"  "+  chahed.getType() + " "+ "DT";

                ui->la_msg_emp_mois->setText(m);

}

