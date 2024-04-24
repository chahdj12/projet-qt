#ifndef gestion_employee_h
#define gestion_employee_h

#include <QMainWindow>
#include "employe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gestion_employee; }
QT_END_NAMESPACE

class gestion_employee : public QMainWindow
{
    Q_OBJECT

public:
    gestion_employee(QWidget *parent = nullptr);
    ~gestion_employee();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_modifier_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_slot_clicked();
    void on_pb_find_clicked();

    void on_pb_pdf_clicked();

    void on_pb_state_clicked();

private:
    Ui::gestion_employee *ui;
    employe employe;
};

#endif // gestion_employee_h
