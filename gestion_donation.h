#ifndef GESTION_DONATION_H
#define GESTION_DONATION_H

#include <QMainWindow>

namespace Ui {
class gestion_donation;
}

class gestion_donation : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_donation(QWidget *parent = nullptr);
    ~gestion_donation();

private:
    Ui::gestion_donation *ui;
};

#endif // GESTION_DONATION_H
