#include "gestion_guests.h"
#include "ui_gestion_guests.h"

gestion_guests::gestion_guests(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_guests)
{
    ui->setupUi(this);
}

gestion_guests::~gestion_guests()
{
    delete ui;
}
