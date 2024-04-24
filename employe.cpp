#include "employe.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>




employe::employe() {
    id = 0;
    phone_number = 0;
    work_hours = 0;
}

employe::employe(int id, QString name, QString lastname, int phone_number, QString email, QString adress, QString salary, QString hiring_date, int work_hours, QString role) {
    this->id = id;
    this->name = name;
    this->lastname = lastname;
    this->phone_number = phone_number;
    this->email = email;
    this->adress = adress;
    this->salary = salary;
    this->hiring_date = hiring_date;
    this->work_hours = work_hours;
    this->role = role;
}

int employe::getid() { return id; }
QString employe::getname() { return name; }
QString employe::getlastname() { return lastname; }
int employe::getphone_number() { return phone_number; }
QString employe::getemail() { return email; }
QString employe::getadress() { return adress; }
QString employe::getsalary() { return salary; }
QString employe::gethiring_date() { return hiring_date; }
int employe::getwork_hours() { return work_hours; }
QString employe::getrole() { return role; }

void employe::setid(int id) { this->id = id; }
void employe::setname(QString name) { this->name = name; }
void employe::setlastname(QString lastname) { this->lastname = lastname; }
void employe::setphone_number(int phone_number) { this->phone_number = phone_number; }
void employe::setemail(QString email) { this->email = email; }
void employe::setadress(QString adress) { this->adress = adress; }
void employe::setsalary(QString salary) { this->salary = salary; }
void employe::sethiring_date(QString hiring_date) { this->hiring_date = hiring_date; }
void employe::setwork_hours(int work_hours) { this->work_hours = work_hours; }
void employe::setrole(QString role) { this->role = role; }

bool employe::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO employe (id, name, lastname, phone_number, email, adress, salary, hiring_date, work_hours, role) "
                  "VALUES (:id, :name, :lastname, :phone_number, :email, :adress, :salary, :hiring_date, :work_hours, :role)");
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":lastname", lastname);
    query.bindValue(":phone_number", phone_number);
    query.bindValue(":email", email);
    query.bindValue(":adress", adress);
    query.bindValue(":salary", salary);
    query.bindValue(":hiring_date", hiring_date);
    query.bindValue(":work_hours", work_hours);
    query.bindValue(":role", role);

    bool success = query.exec();
    if (!success) {
        qDebug() << "Error in adding employee:" << query.lastError().text();
    }
    return success;
}

QSqlQueryModel* employe::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe");
    return model;
}

bool employe::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM employe WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool employe::modifier(int id, QString name, QString lastname, int phone_number, QString email, QString adress, QString salary, QString hiring_date, int work_hours, QString role) {
    QSqlQuery query;
    query.prepare("UPDATE employe SET name = :name, lastname = :lastname, phone_number = :phone_number, email = :email, adress = :adress, "
                  "salary = :salary, hiring_date = :hiring_date, work_hours = :work_hours, role = :role WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":lastname", lastname);
    query.bindValue(":phone_number", phone_number);
    query.bindValue(":email", email);
    query.bindValue(":adress", adress);
    query.bindValue(":salary", salary);
    query.bindValue(":hiring_date", hiring_date);
    query.bindValue(":work_hours", work_hours);
    query.bindValue(":role", role);
    return query.exec();
}

employe employe::rechercherParId(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM employe WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString lastname = query.value(2).toString();
        int phone_number = query.value(3).toInt();
        QString email = query.value(4).toString();
        QString adress = query.value(5).toString();
        QString salary = query.value(6).toString();
        QString hiring_date = query.value(7).toString();
        int work_hours = query.value(8).toInt();
        QString role = query.value(9).toString();

        return employe(id, name, lastname, phone_number, email, adress, salary, hiring_date, work_hours, role);
    }

    // Retourner un employé vide si aucun n'est trouvé
    return employe();
}

void employe::printPDF(){


    QPdfWriter pdf("C:\\Users\\USER\\Desktop\\pdf_employe\\employe_report.pdf");

        QPainter painter(&pdf);
        int i = 4000;

        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1200, 1200, "Liste des employes");

        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 15));
        painter.drawRect(100, 100, 7300, 2600);
        painter.drawRect(0, 3000, 9600, 500);

        painter.setFont(QFont("Arial", 9));
        painter.drawText(200, 3300, "id ");
        painter.drawText(1200, 3300, "name");
        painter.drawText(2400, 3300, "lastname");
        painter.drawText(3600, 3300, "phone_number");
        painter.drawText(5800, 3300, "email");
        painter.drawText(7000, 3300, "adress");
        painter.drawText(8200, 3300, "salary");
        painter.drawText(9400, 3300, "hiring_date");
        painter.drawText(10600, 3300, "work_hours");
        painter.drawText(11800, 3300, "role");





        QSqlQuery query;
        query.prepare("select * from employe");
        query.exec();
        while (query.next())
        {
            painter.drawText(200, i, query.value(0).toString());
            painter.drawText(1200, i, query.value(1).toString());
            painter.drawText(2400, i, query.value(2).toString());
            painter.drawText(3600, i, query.value(3).toString());
            painter.drawText(5800, i, query.value(4).toString());
             painter.drawText(7000, i, query.value(5).toString());
             painter.drawText(8200, i, query.value(6).toString());
             painter.drawText(9400, i, query.value(7).toString());
             painter.drawText(10600, i, query.value(8).toString());
             painter.drawText(11800, i, query.value(9).toString());
            i = i + 500;
        }

        QMessageBox::information(nullptr, "PDF Créé", "Un fichier PDF a été créé.");







}
