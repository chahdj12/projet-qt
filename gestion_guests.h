#ifndef GESTION_GUESTS_H
#define GESTION_GUESTS_H

#include <QMainWindow>

namespace Ui {
class gestion_guests;
}

class gestion_guests : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_guests(QWidget *parent = nullptr);
    ~gestion_guests();

private:
    Ui::gestion_guests *ui;
};

#endif // GESTION_GUESTS_H
