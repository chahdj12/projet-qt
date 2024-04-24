#include "customwidget.h"

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{ QPixmap backgroundImage("C:/Users/USER/OneDrive/Bureau/icons/Rectangle 1.png");
    // Définir l'image comme arrière-plan du widget
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, backgroundImage);
    setPalette(palette);

}

