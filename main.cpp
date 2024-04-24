#include "menu.h" // Inclure le fichier d'en-tête de menu.h

#include "gestion_oeuvre.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include<QWidget>
#include "connection.h"
#include "menu.h" // Include the menu header
#include "secdialog.h" // Include the menu header

#include "connection.h" // Include the connection header
#include <QApplication>
#include <QMessageBox> // Include QMessageBox for connection status message

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();

    SecDialog secdialogWindow; // Créer une instance de menu
    if(test)
    {
        secdialogWindow.show();
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}

