#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "mainwindow.h"
#include "gestion_oeuvre.h"
#include "gestion_employee.h"
#include "gestion_guests.h"
#include "gestion_donation.h" // Inclure le fichier d'en-tête de gestion_donation.h

namespace Ui {
    class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButton_8_clicked(); // Slot pour le bouton pushButton8
    void on_pushButton_6_clicked(); // Slot pour le bouton pushButton6
    void on_pushButton_7_clicked(); // Slot pour le bouton pushButton7
    void on_pushButton_3_clicked(); // Slot pour le bouton pushButton3
    void on_pushButton_5_clicked(); // Slot pour le bouton pushButton5

private:
    Ui::menu *ui;
    MainWindow *mainWindow;
    gestion_oeuvre *gestionOeuvre;
    gestion_employee *gestionEmployee;
    gestion_guests *gestionGuests;
    gestion_donation *gestionDonation; // Ajouter une instance de gestion_donation
};

#endif // MENU_H
