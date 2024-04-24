#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQueryModel>

class employe
{
public:
    employe();
    employe(int id, QString name, QString lastname, int phone_number, QString email, QString adress, QString salary, QString hiring_date, int work_hours, QString role);

    int getid();
    QString getname();
    QString getlastname();
    int getphone_number();
    QString getemail();
    QString getadress();
    QString getsalary();
    QString gethiring_date();
    int getwork_hours();
    QString getrole();

    void setid(int id);
    void setname(QString name);
    void setlastname(QString lastname);
    void setphone_number(int phone_number);
    void setemail(QString email);
    void setadress(QString adress);
    void setsalary(QString salary);
    void sethiring_date(QString hiring_date);
    void setwork_hours(int work_hours);
    void setrole(QString role);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier(int id, QString name, QString lastname, int phone_number, QString email, QString adress, QString salary, QString hiring_date, int work_hours, QString role);
    employe rechercherParId(int id);
    void printPDF();
private:
    int id;
    QString name;
    QString lastname;
    int phone_number;
    QString email;
    QString adress;
    QString salary;
    QString hiring_date;
    int work_hours;
    QString role;
};

#endif // EMPLOYE_H
