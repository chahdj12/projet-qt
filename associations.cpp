#include "associations.h"
#include <QSqlQuery>
#include <QDebug>
#include <iostream>
#include <QSqlQueryModel>
#include <QList>
using namespace std;
#include <QString>
#include <QtSql/QSqlError>
#include <stdexcept>


associations::associations(){
         idDon= 0;
         type= "";
        destinataire = "";
        montant= 0.0;
        idOeuvre= 0;
        moin = "";
}
associations::associations(int idDon ,QString type,QString destinataire,float montant,int idOeuvre,QString moin)
{
    this->idDon = idDon;
        this->type = type;
        this->destinataire = destinataire;
        this->montant = montant ;
        this->idOeuvre = idOeuvre;
    this->moin = moin;
    }



// ajout
/*bool associations::ajouter() {
    QSqlQuery query;
    QString res =QString::number(idDon);
    QString chahd =QString::number(idOeuvre);
     QString lila =QString::number(montant);
    query.prepare("INSERT INTO ASSOCIATIONS  (IDDON, TYPE, DESTINATAIRE, MONTANT,IDOEUVRE"
                  ") "
                  "VALUES (:IDDON, :TYPE, :DESTINATAIRE, :MONTANT, :IDOEUVRE)");
    query.bindValue(":IDDON", res);
    query.bindValue(":TYPE", type);
    query.bindValue(":DESTINATAIRE", destinataire);
    query.bindValue(":MONTANT", lila);
    query.bindValue(":IDOEUVRE", chahd);
    return query.exec();
}*/
bool associations::ajouter() {
    QSqlQuery query;
    QString res = QString::number(idDon);
    QString chahd = QString::number(idOeuvre);
    QString lila = QString::number(montant);
    query.prepare("INSERT INTO ASSOCIATIONS (IDDON, TYPE, DESTINATAIRE, MONTANT, IDOEUVRE, MOIN) "
                  "VALUES (:IDDON, :TYPE, :DESTINATAIRE, :MONTANT, :IDOEUVRE, :MOIN)");
    query.bindValue(":IDDON", res);
    query.bindValue(":TYPE", type);
    query.bindValue(":DESTINATAIRE", destinataire);
    query.bindValue(":MONTANT", lila);
    query.bindValue(":IDOEUVRE", chahd);
    query.bindValue(":MOIN", moin); // Ajout de MOIN
    return query.exec();
}

QSqlQueryModel* associations::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ASSOCIATIONS");

       model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDDON"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATAIRE"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("MONTANT"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDOEUVRE"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("MOIN"));

 return model;
}


bool associations::mod(int idDon){
    QSqlQuery query;
       QString res = QString::number(idDon);
       QString chahd = QString::number(idOeuvre);
       QString lila = QString::number(montant);
       query.prepare("UPDATE ASSOCIATIONS SET TYPE=:TYPE, DESTINATAIRE=:DESTINATAIRE, MONTANT=:MONTANT, IDOEUVRE=:IDOEUVRE, MOIN=:MOIN WHERE IDDON=:IDDON");
       query.bindValue(":IDDON", res);
       query.bindValue(":TYPE", type);
       query.bindValue(":DESTINATAIRE", destinataire);
       query.bindValue(":MONTANT", lila);
       query.bindValue(":IDOEUVRE", chahd);
       query.bindValue(":MOIN", moin); // Ajout de MOIN
       return query.exec();

}
bool associations::supprimer(int idDon) {
    QSqlQuery query;

       query.prepare("delete from ASSOCIATIONS where idDon=:IDDON");

       query.bindValue(":IDDON", idDon);
       query.bindValue(":TYPE", type);
       query.bindValue(":DESTINATAIRE", destinataire);
       query.bindValue(":MONTANT", montant);
       query.bindValue(":IDOEUVRE", idOeuvre);
       query.bindValue(":MOIN", moin);

       return  query.exec();
}



QSqlQueryModel* associations::chercher_id(int idDon)
 {
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM ASSOCIATIONS WHERE IDDON = " + QString::number(idDon));

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDDON"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATAIRE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("MONTANT"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDOEUVRE"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("MOIN"));
     return model;
}
QSqlQueryModel* associations::chercher_destinataire(QString destinataire)
 {
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM ASSOCIATIONS WHERE DESTINATAIRE LIKE '%" + destinataire + "%'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDDON"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATAIRE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("MONTANT"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDOEUVRE"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("MOIN"));
     return model;
}
QSqlQueryModel* associations::chercher_type( QString type)
{
   QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM ASSOCIATIONS WHERE TYPE LIKE '%" + type + "%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDDON"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATAIRE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MONTANT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDOEUVRE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MOIN")); // Ajout de MOIN

    return model;
}
QSqlQueryModel* associations::tri_montant()
{
   QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM ASSOCIATIONS ORDER BY MONTANT ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDDON"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATAIRE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MONTANT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDOEUVRE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MOIN"));
    return model;
}
/*float associations::getTotalDonationsAmount(){
    QSqlQuery query;
        query.prepare("SELECT SUM(MONTANT) FROM ASSOCIATIONS");
        float totalDon = 0.0f;
            if (query.next()) {
                totalDon = query.value(0).toFloat();
            }

            return totalDon;

}*/
QList<float> associations::getAllDonationsAmounts() {
    QList<float> donationAmounts; // List to store all donation amounts

    QSqlQuery query("SELECT MONTANT FROM ASSOCIATIONS");
    while (query.next()) {
        float donationAmount = query.value(0).toFloat(); // Get each donation amount
        donationAmounts.append(donationAmount); // Append it to the list
    }

    return donationAmounts;
}
associations associations::getHighestDonation() {
    QSqlQuery query;
             query.prepare("SELECT * FROM ASSOCIATIONS ORDER BY MONTANT DESC ");

             if (!query.exec()) {
                 qDebug() << "Erreur :" << query.lastError().text();
                 return associations();
             }

             if (query.next()) {
                 int idDon = query.value(0).toInt();
                 QString type = query.value(1).toString();
                 QString destinataire = query.value(2).toString();
                 float montant = query.value(3).toFloat();
                     int idOeuvre = query.value(4).toInt();
                    QString moin = query.value(5).toString();



                 associations chahed(idDon, type,destinataire,montant,idOeuvre,moin); // Assurez-vous d'inclure toutes les informations nécessaires
                 return chahed;
             } else {
                 qDebug() << "Aucun employé trouvé.";

                 return associations();
             }
}
