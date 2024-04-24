#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu),
    mainWindow(nullptr),
    gestionOeuvre(nullptr),
    gestionEmployee(nullptr),
    gestionGuests(nullptr),
    gestionDonation(nullptr) // Initialiser gestionDonation à nullptr
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
    delete mainWindow;
    delete gestionOeuvre;
    delete gestionEmployee;
    delete gestionGuests;
    delete gestionDonation; // Libérer la mémoire allouée pour gestionDonation
}

void menu::on_pushButton_8_clicked()
{
    if (!gestionGuests) {
        gestionGuests = new gestion_guests;
        gestionGuests->show();
    } else {
        gestionGuests->show();
    }
}

void menu::on_pushButton_6_clicked()
{
    if (!mainWindow) { // Si gestionDonation n'est pas encore créé
        mainWindow = new MainWindow; // Créer une nouvelle instance de gestion_donation
        mainWindow->show(); // Afficher l'interface de gestion_donation
    } else {
        mainWindow->show(); // Si gestionDonation existe déjà, simplement l'afficher
    }
}

void menu::on_pushButton_7_clicked()
{
    if (!gestionEmployee) {
        gestionEmployee = new gestion_employee;
        gestionEmployee->show();
    } else {
        gestionEmployee->show();
    }
}

void menu::on_pushButton_3_clicked()
{
    if (!mainWindow) {
        mainWindow = new MainWindow;
        mainWindow->show();
    } else {
        mainWindow->show();
    }
}

void menu::on_pushButton_5_clicked()
{
    if (!gestionOeuvre) {
        gestionOeuvre = new gestion_oeuvre;
        gestionOeuvre->show();
    } else {
        gestionOeuvre->show();
    }
}
