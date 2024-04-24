#include "oeuvre.h"
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>



oeuvre::oeuvre() {
    id = 0;
}

oeuvre::oeuvre(int id, QString entered_date, QString exposition_date, QString type, QString price, QString rating) {
    this->id = id;
    this->entered_date = entered_date;
    this->exposition_date = exposition_date;
    this->type = type;
    this->price = price;
    this->rating = rating;
}

int oeuvre::getid() { return id; }
QString oeuvre::getentered_date() { return entered_date; }
QString oeuvre::getexposition_date() { return exposition_date; }
QString oeuvre::gettype() { return type; }
QString oeuvre::getprice() { return price; }
QString oeuvre::getrating() { return rating; }

void oeuvre::setid(int id) { this->id = id; }
void oeuvre::setentered_date(QString entered_date) { this->entered_date = entered_date; }
void oeuvre::setexposition_date(QString exposition_date) { this->exposition_date = exposition_date; }
void oeuvre::settype(QString type) { this->type = type; }
void oeuvre::setprice(QString price) { this->price = price; }
void oeuvre::setrating(QString rating) { this->rating = rating; }

bool oeuvre::ajouter() {
    if (id == 0 || entered_date.isEmpty() || exposition_date.isEmpty() || type.isEmpty() || price.isEmpty() || rating.isEmpty()) {
        return false; // Les saisies sont invalides, donc on ne peut pas ajouter l'oeuvre
    }

    QSqlQuery query;
    query.prepare("INSERT INTO oeuvre (id, entered_date, exposition_date, type, price, rating) "
                  "VALUES (:id, :entered_date, :exposition_date, :type, :price, :rating)");
    query.bindValue(":id", id);
    query.bindValue(":entered_date", entered_date);
    query.bindValue(":exposition_date", exposition_date);
    query.bindValue(":type", type);
    query.bindValue(":price", price);
    query.bindValue(":rating", rating);
    return query.exec();
}

QSqlQueryModel* oeuvre::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM oeuvre");
    return model;
}

bool oeuvre::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM oeuvre WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool oeuvre::modifier(int id, QString entered_date, QString exposition_date, QString type, QString price, QString rating) {
    QSqlQuery query;
    query.prepare("UPDATE oeuvre SET entered_date = :entered_date, exposition_date = :exposition_date, type = :type, "
                  "price = :price, rating = :rating WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":entered_date", entered_date);
    query.bindValue(":exposition_date", exposition_date);
    query.bindValue(":type", type);
    query.bindValue(":price", price);
    query.bindValue(":rating", rating);
    return query.exec();
}

oeuvre oeuvre::rechercherParId(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM oeuvre WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int id = query.value(0).toInt();
        QString entered_date = query.value(1).toString();
        QString exposition_date = query.value(2).toString();
        QString type = query.value(3).toString();
        QString price = query.value(4).toString();
        QString rating = query.value(5).toString();

        return oeuvre(id, entered_date, exposition_date, type, price, rating);
    }

    // Retourner une oeuvre vide si elle n'est pas trouvée
    return oeuvre();
}

void oeuvre::printPDF(){

    QPdfWriter pdf("C:\\Users\\USER\\Desktop\\pdf_employe\\oeuvre_report.pdf");

    QPainter painter(&pdf);
    int i = 4000;

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(1200, 1200, "Liste des oeuvres");

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 15));
    painter.drawRect(100, 100, 7300, 2600);
    painter.drawRect(0, 3000, 9600, 500);

    painter.setFont(QFont("Arial", 9));
    painter.drawText(200, 3300, "id ");
    painter.drawText(1200, 3300, "entered_date");
    painter.drawText(2400, 3300, "exposition_date");
    painter.drawText(3600, 3300, "type");
    painter.drawText(5800, 3300, "price");
    painter.drawText(7000, 3300, "rating");


    QSqlQuery query;
    query.prepare("select * from OEUVRE");
    query.exec();
    while (query.next())
    {
        painter.drawText(200, i, query.value(0).toString());
        painter.drawText(1200, i, query.value(1).toString());
        painter.drawText(2400, i, query.value(2).toString());
        painter.drawText(3600, i, query.value(3).toString());
        painter.drawText(5800, i, query.value(4).toString());
         painter.drawText(7000, i, query.value(5).toString());
        i = i + 500;
    }

    QMessageBox::information(nullptr, "PDF Créé", "Un fichier PDF a été créé.");




}
