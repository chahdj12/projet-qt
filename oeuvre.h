#ifndef OEUVRE_H
#define OEUVRE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>

class oeuvre
{
public:
    oeuvre();
    oeuvre(int,QString,QString,QString,QString,QString);
    int getid();
    QString getentered_date();
    QString getexposition_date();
    QString gettype();
    QString getprice();
    QString getrating();
    void setid(int);
    void setentered_date(QString);
    void setexposition_date(QString);
    void settype(QString);
    void setprice(QString);
    void setrating(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int id, QString entered_date, QString exposition_date, QString type, QString price, QString rating);
    oeuvre rechercherParId(int id); // Nouvelle méthode pour rechercher une oeuvre par ID
    void printPDF();
private:
    int id;
    QString entered_date;
    QString exposition_date;
    QString type;
    QString price;
    QString rating;
};

#endif // OEUVRE_H
