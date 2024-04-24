#include "iconwidget.h"
#include <QPixmap>
#include <QPalette>
iconwidget::iconwidget(QWidget *parent):iconwidget(parent)
{
    QPixmap backgroundImage("C:/Users/USER/OneDrive/Bureau/icons/Rectangle 1.png"); // Remplacez ":/path/to/your/image.png" par le chemin réel de votre image

       // Définir l'image comme arrière-plan du widget
       setAutoFillBackground(true);
       QPalette palette;
       palette.setBrush(QPalette::Background, backgroundImage);
       setPalette(palette);
}
