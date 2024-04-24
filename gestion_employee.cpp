#include "gestion_employee.h"
#include "ui_gestion_employee.h"
#include "employe.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QInputDialog>
#include <QSqlQuery>
#include<QMessageBox>
#include "gestion_employee.h"
#include "ui_gestion_employee.h"
#include "employe.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QBarSeries>
#include <QBarSet>
#include <QChart>
#include <QChartView>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QPainter>
#include <QtCharts>
#include <QDebug>
// Ajouté pour le débogage, facultatif selon les besoins
#include <QSqlRecord>


gestion_employee::gestion_employee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_employee)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 999999, this));
    ui->le_phone_number->setValidator(new QIntValidator(0, 999999999, this));
    ui->le_work_hours->setValidator(new QIntValidator(0, 24, this));
    ui->tab_employe->setModel(employe.afficher());
}

gestion_employee::~gestion_employee()
{
    delete ui;
}

void gestion_employee::on_pb_ajouter_clicked()
{
    int id = ui->le_id->text().toInt();
    QString name = ui->le_name->text();
    QString lastname = ui->le_last_name->text();
    int phone_number = ui->le_phone_number->text().toInt();
    QString email = ui->le_email->text();
    QString adress = ui->le_adress->text();
    QString salary = ui->le_salary->text();
    QString hiring_date = ui->le_hiring_date->text();
    int work_hours = ui->le_work_hours->text().toInt();
    QString role = ui->le_role->text();

    if (id == 0 || name.isEmpty() || lastname.isEmpty() || phone_number == 0 || email.isEmpty() || adress.isEmpty() || salary.isEmpty() || hiring_date.isEmpty() || work_hours == 0 || role.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    employe.setid(id);
    employe.setname(name);
    employe.setlastname(lastname);
    employe.setphone_number(phone_number);
    employe.setemail(email);
    employe.setadress(adress);
    employe.setsalary(salary);
    employe.sethiring_date(hiring_date);
    employe.setwork_hours(work_hours);
    employe.setrole(role);

    bool test = employe.ajouter();
    if (test) {
        ui->tab_employe->setModel(employe.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajout effectué"), QObject::tr("Ajout effectué avec succès."), QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur d'ajout"), QObject::tr("Erreur lors de l'ajout."), QMessageBox::Ok);
    }
}

void gestion_employee::on_pb_modifier_clicked()
{
    int id = ui->le_id->text().toInt();
    QString name = ui->le_name->text();
    QString lastname = ui->le_last_name->text();
    int phone_number = ui->le_phone_number->text().toInt();
    QString email = ui->le_email->text();
    QString adress = ui->le_adress->text();
    QString salary = ui->le_salary->text();
    QString hiring_date = ui->le_hiring_date->text();
    int work_hours = ui->le_work_hours->text().toInt();
    QString role = ui->le_role->text();

    if (id == 0 || name.isEmpty() || lastname.isEmpty() || phone_number == 0 || email.isEmpty() || adress.isEmpty() || salary.isEmpty() || hiring_date.isEmpty() || work_hours == 0 || role.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    bool test = employe.modifier(id, name, lastname, phone_number, email, adress, salary, hiring_date, work_hours, role);
    if (test) {
        ui->tab_employe->setModel(employe.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modification effectuée"), QObject::tr("Modification effectuée avec succès."), QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de modification"), QObject::tr("Erreur lors de la modification."), QMessageBox::Ok);
    }
}

void gestion_employee::on_pb_supprimer_clicked()
{
    // Demande de confirmation de la suppression à l'utilisateur
        bool ok;
        int id = QInputDialog::getInt(this, tr("Supprimer une employe"), tr("Entrez l'ID de l'employe que vous voulez supprimer:"), 0, 0, 1000000, 1, &ok);
        if (ok) {
            // Tentative de suppression de l'employe dans la base de données
            if (employe.supprimer(id)) {
                QMessageBox::information(nullptr, QObject::tr("Suppression réussie"),
                                         QObject::tr("L'employe a été supprimée avec succès."), QMessageBox::Ok);
                ui->tab_employe->setModel(employe.afficher());
            } else {
                QMessageBox::critical(nullptr, QObject::tr("Erreur de suppression"),
                                      QObject::tr("Échec de la suppression de l'employe."), QMessageBox::Ok);
            }
        }
}

void gestion_employee::on_pb_slot_clicked()
{
    // Création d'un modèle QSqlQueryModel pour stocker les données des employes triés
    QSqlQueryModel* sortedModel = new QSqlQueryModel(this);

    // Exécution de la requête SQL pour trier les employes par leur ID
    sortedModel->setQuery("SELECT * FROM employe ORDER BY id");

    // Définition du modèle trié comme modèle de données pour le deuxième tableau
    ui->tab_employe_2->setModel(sortedModel);
}

void gestion_employee::on_pb_find_clicked()
{
    // Récupération de l'ID saisi par l'utilisateur
    int id = ui->le_id->text().toInt();

    // Recherche de l'employe dans la base de données par son ID
    QSqlQuery query;
    query.prepare("SELECT * FROM employe WHERE id = ?");
    query.addBindValue(id);

    if (query.exec()) {
        if (query.next()) {
           QMessageBox::warning(this, tr(" l employe est trouvé"), tr(" l employe est trouvé avec cet ID."), QMessageBox::Ok);
        } else {
            QMessageBox::warning(this, tr("Aucun employe trouvé"), tr("Aucun employe trouvé avec cet ID."), QMessageBox::Ok);
        }
    } else {
        QMessageBox::critical(this, tr("Erreur de recherche"), tr("Une erreur s'est produite lors de la recherche de l'employe."), QMessageBox::Ok);
    }
}

void gestion_employee::on_pb_pdf_clicked()
{
    employe.printPDF();
}

void gestion_employee::on_pb_state_clicked()
{
    // Créer une série de barres pour représenter les données de salaire
    QBarSeries *series = new QBarSeries();

    // Récupérer les données de salaire des employés depuis la base de données
    QSqlQueryModel* model = employe.afficher();

    // Indice des colonnes dans le modèle de requête
    int salaryColumn = model->record().indexOf("salary");

    // Créer une map pour stocker les ensembles de barres pour chaque catégorie de salaire
    QMap<QString, QBarSet*> barSets;

    // Parcourir le modèle et ajouter les données à leurs ensembles de barres respectifs
    for (int row = 0; row < model->rowCount(); ++row) {
        QString salaryString = model->data(model->index(row, salaryColumn)).toString();
        salaryString.remove("$");
        int salary = salaryString.toInt();
        QString category;

        // Déterminer la catégorie en fonction du salaire
        if (salary >= 1000) {
            category = "Riche";
        } else if (salary >= 600) {
            category = "Passable";
        } else {
            category = "Faible";
        }

        // Vérifier si l'ensemble de barres pour cette catégorie existe déjà, sinon le créer
        if (!barSets.contains(category)) {
            QBarSet *set = new QBarSet(category);
            barSets.insert(category, set);
            series->append(set); // Ajouter l'ensemble de barres à la série
        }

        // Ajouter la valeur de salaire à l'ensemble de barres approprié
        barSets[category]->append(salary);
    }

    // Créer le graphique et définir le titre
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques de salaire des employés");

    // Créer les axes
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(barSets.keys()); // Ajouter les catégories à l'axe X
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Créer la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Afficher la vue du graphique
    chartView->show();
}
