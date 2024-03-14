#include "associations.h"
#include <QSqlQuery>
#include <QDebug>
#include <iostream>
#include <QSqlQueryModel>

using namespace std;
#include <QString>

associations::associations(){
         idDon= 0;
         type= "";
        destinataire = "";
        montant= 0.0;
        idOeuvre= 0;
}
associations::associations(int idDon ,QString type,QString destinataire,float montant,int idOeuvre)
{
    this->idDon = idDon;
        this->type = type;
        this->destinataire = destinataire;
        this->montant = montant ;
        this->idOeuvre = idOeuvre;
    }



// ajout
bool associations::ajouter() {
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
}

QSqlQueryModel* associations::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ASSOCIATIONS");

       model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDDON"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATAIRE"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("MONTANT"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDOEUVRE"));

 return model;
}


bool associations::mod(int idDon){
QSqlQuery query;

 QString res=QString::number(idDon);
 QString chahd =QString::number(idOeuvre);
  QString lila =QString::number(montant);
        query.prepare("UPDATE ASSOCIATIONS SET TYPE=:TYPE, DESTINATAIRE=:DESTINATAIRE, MONTANT=:MONTANT, IDOEUVRE =:IDOEUVRE  where idDon=:IDDON ");
        query.bindValue(":IDDON", res);
        query.bindValue(":TYPE", type);
        query.bindValue(":DESTINATAIRE", destinataire);
        query.bindValue(":MONTANT", lila);
        query.bindValue(":IDOEUVRE", chahd);
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
     return model;
}
