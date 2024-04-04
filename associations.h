#ifndef ASSOCIATIONS_H
#define ASSOCIATIONS_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class associations
{private:
    int idDon;
    QString type;
    QString destinataire;
    float montant;
    int idOeuvre;
public:
    //constructeurs
    associations();
    associations(int idD ,QString t,QString d,float m,int idO);

    //Getters
    int getIdDon() const { return idDon; }
      QString getType() const { return type; }
      QString getDestinataire() const { return destinataire; }
      float getMontant() const { return montant; }
      int getIdOeuvre() const { return idOeuvre; }
    // setters
      void setIdDon(int idD) { idDon = idD; }
         void setType(const QString &t) { type = t; }
         void setDestinataire(const QString &d) { destinataire = d; }
         void setMontant(float m) { montant = m; }
         void setIdOeuvre(int idO) { idOeuvre = idO; }
    //methods
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int idDon);
bool mod(int idDon);
QSqlQueryModel* chercher_id(int iDdon);
QSqlQueryModel* chercher_destinataire(QString destinataire);
QSqlQueryModel* chercher_type(QString type);
QSqlQueryModel* tri_montant();
 float getTotalDonationsAmount();
 QList<float> getAllDonationsAmounts() ;
 float donofmonth();
 associations getHighestDonation() ;
 void insertCalendar();




};

#endif // ASSOCIATIONS_H
