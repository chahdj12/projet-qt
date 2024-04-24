#include "gestion_oeuvre.h"
#include "ui_gestion_oeuvre.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QIntValidator>
#include <QSqlQuery>
#include "oeuvre.h"
#include <QBarSeries>
#include <QBarSet>
#include <QChart>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QSqlRecord>




gestion_oeuvre::gestion_oeuvre(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_oeuvre)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 999999, this));
    ui->le_rating->setValidator(new QIntValidator(0, 999999, this));

    ui->tab_oeuvre->setModel(oeuvre.afficher());
}

gestion_oeuvre::~gestion_oeuvre()
{
    delete ui;
}

void gestion_oeuvre::on_pb_ajouter_clicked()
{
    // Récupération des valeurs saisies par l'utilisateur
    int id = ui->le_id->text().toInt();
    QString entered_date = ui->le_entered_date->text();
    QString exposition_date = ui->le_exposition_date->text();
    QString type = ui->le_type->text();
    QString price = ui->le_price->text();
    QString rating = ui->le_rating->text();

    // Vérification de la validité des champs
    if (id == 0 || entered_date.isEmpty() || exposition_date.isEmpty() || type.isEmpty() || price.isEmpty() || rating.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur d'ajout"),
                              QObject::tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    oeuvre.setid(id);
    oeuvre.setentered_date(entered_date);
    oeuvre.setexposition_date(exposition_date);
    oeuvre.settype(type);
    oeuvre.setprice(price);
    oeuvre.setrating(rating);

    // Tentative d'ajout dans la base de données
    bool test = oeuvre.ajouter();
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Ajout effectué"),
                                 QObject::tr("Ajout effectué avec succès."), QMessageBox::Ok);
        ui->tab_oeuvre->setModel(oeuvre.afficher());
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur d'ajout"),
                              QObject::tr("Erreur lors de l'ajout."), QMessageBox::Ok);
    }
}

void gestion_oeuvre::on_pb_modifier_clicked()
{
    // Récupération des valeurs saisies par l'utilisateur
    int id = ui->le_id->text().toInt();
    QString entered_date = ui->le_entered_date->text();
    QString exposition_date = ui->le_exposition_date->text();
    QString type = ui->le_type->text();
    QString price = ui->le_price->text();
    QString rating = ui->le_rating->text();

    // Vérification de la validité des champs
    if (id == 0 || entered_date.isEmpty() || exposition_date.isEmpty() || type.isEmpty() || price.isEmpty() || rating.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de Modification"),
                              QObject::tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    // Tentative de modification de l'oeuvre dans la base de données
    if (oeuvre.modifier(id, entered_date, exposition_date, type, price, rating)) {
        QMessageBox::information(nullptr, QObject::tr("Modification Réussie"),
                                 QObject::tr("Les informations de l'oeuvre ont été mises à jour."), QMessageBox::Ok);
        ui->tab_oeuvre->setModel(oeuvre.afficher());
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de Modification"),
                              QObject::tr("Impossible de mettre à jour les informations de l'oeuvre."), QMessageBox::Ok);
    }
}

void gestion_oeuvre::on_pb_supprimer_clicked()
{
    // Demande de confirmation de la suppression à l'utilisateur
    bool ok;
    int id = QInputDialog::getInt(this, tr("Supprimer une oeuvre"), tr("Entrez l'ID de l'oeuvre que vous voulez supprimer:"), 0, 0, 1000000, 1, &ok);
    if (ok) {
        // Tentative de suppression de l'oeuvre dans la base de données
        if (oeuvre.supprimer(id)) {
            QMessageBox::information(nullptr, QObject::tr("Suppression réussie"),
                                     QObject::tr("L'oeuvre a été supprimée avec succès."), QMessageBox::Ok);
            ui->tab_oeuvre->setModel(oeuvre.afficher());
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Erreur de suppression"),
                                  QObject::tr("Échec de la suppression de l'oeuvre."), QMessageBox::Ok);
        }
    }
}

void gestion_oeuvre::on_pb_slot_clicked()
{
    // Création d'un modèle QSqlQueryModel pour stocker les données des oeuvres triées
    QSqlQueryModel* sortedModel = new QSqlQueryModel(this);

    // Exécution de la requête SQL pour trier les oeuvres par leur ID
    sortedModel->setQuery("SELECT * FROM oeuvre ORDER BY id");

    // Définition du modèle trié comme modèle de données pour le deuxième tableau
    ui->tableView_2->setModel(sortedModel);
}

void gestion_oeuvre::on_pb_search_clicked()
{
    // Récupération de l'ID saisi par l'utilisateur
    int id = ui->le_id->text().toInt();

    // Recherche de l'oeuvre dans la base de données par son ID
    QSqlQuery query;
    query.prepare("SELECT * FROM oeuvre WHERE id = ?");
    query.addBindValue(id);

    if (query.exec()) {
        if (query.next()) {
            QMessageBox::warning(this, tr("l oeuvre est trouvée"), tr("l oeuvre est trouvée avec cet ID."), QMessageBox::Ok);

        } else {
            QMessageBox::warning(this, tr("Aucune oeuvre trouvée"), tr("Aucune oeuvre trouvée avec cet ID."), QMessageBox::Ok);
        }
    } else {
        QMessageBox::critical(this, tr("Erreur de recherche"), tr("Une erreur s'est produite lors de la recherche de l'oeuvre."), QMessageBox::Ok);
    }
}

void gestion_oeuvre::on_pb_pdf_clicked()
{
    oeuvre.printPDF();
}

void gestion_oeuvre::on_pb_state_clicked()
{
    // Création d'une nouvelle série de barres pour stocker les données de rating
    QBarSeries *series = new QBarSeries();

    // Détermination des colonnes pertinentes dans le modèle SQL
    int ratingColumn = oeuvre.afficher()->record().indexOf("rating");

    // Création des ensembles de barres pour chaque catégorie de rating
    QBarSet *perfectSet = new QBarSet("Perfect");
    QBarSet *passableSet = new QBarSet("Passable");
    QBarSet *weakSet = new QBarSet("Faible");
  QSqlQueryModel* salesModel = oeuvre.afficher();
    // Récupération des données de rating du modèle SQL
    for (int row = 0; row < salesModel->rowCount(); ++row) {
        int rating = salesModel->data(salesModel->index(row, ratingColumn)).toInt();
        if (rating > 10) {
            *perfectSet << rating;
        } else if (rating >= 5 && rating <= 10) {
            *passableSet << rating;
        } else {
            *weakSet << rating;
        }
    }

    // Ajout des ensembles de barres au série
    series->append(perfectSet);
    series->append(passableSet);
    series->append(weakSet);

    // Création d'un nouveau graphique
    QChart *chart = new QChart();

    // Ajout de la série de barres au graphique
    chart->addSeries(series);

    // Création des axes x et y
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append("Perfect");
    axisX->append("Passable");
    axisX->append("Faible");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Création d'une vue de chart pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Affichage du graphique
    chartView->show();
}

