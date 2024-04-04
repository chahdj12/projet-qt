#include "notification.h"

notification::notification()
{

}
void notification::notifAjouterMateriels()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

      // Set an icon for the system tray icon (replace ":/path/to/icon.png" with the actual path to your icon file)
      notifyIcon->setIcon(QIcon("C:/Users/USER/OneDrive/Bureau/icons/BellRinging.png"));

      // Show the system tray icon
      notifyIcon->show();

      // Show a notification message
      notifyIcon->showMessage("Gestion des dons ", "Nouveau don est ajouté", QSystemTrayIcon::Information, 15000);
}

void notification::notifModifierMateriels(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("C:/Users/USER/OneDrive/Bureau/icons/BellRinging.png"));

    notifyIcon->show();
    // Affiche un message d'information avec une durée d'affichage de 15 secondes
    notifyIcon->showMessage("Gestion des Materiels","Nouveau Materiel est modifiée",QSystemTrayIcon::Information,15000);
}


void notification::notifSupprimerMatereils(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon->setIcon(QIcon());
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Materiels","Nouveau Materiel est supprimée",QSystemTrayIcon::Information,15000);
}

/*
void notification::notif_failed(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon->setIcon(QIcon());
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Materiels","Action Failed",QSystemTrayIcon::Critical,15000);
}*/

