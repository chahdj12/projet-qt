#ifndef GESTION_OEUVRE_H
#define GESTION_OEUVRE_H

#include <QMainWindow>
#include "oeuvre.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gestion_oeuvre; }
QT_END_NAMESPACE

class gestion_oeuvre : public QMainWindow
{
    Q_OBJECT

public:
    gestion_oeuvre(QWidget *parent = nullptr);
    ~gestion_oeuvre();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_modifier_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_slot_clicked();
    void on_pb_search_clicked();

    void on_pb_pdf_clicked();

    void on_pb_state_clicked();

private:
    Ui::gestion_oeuvre *ui;
    oeuvre oeuvre;
};

#endif // GESTION_OEUVRE_H
