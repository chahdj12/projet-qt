#include "gestion_donation.h"
#include "ui_gestion_donation.h"

gestion_donation::gestion_donation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_donation)
{
    ui->setupUi(this);
}

gestion_donation::~gestion_donation()
{
    delete ui;
}
