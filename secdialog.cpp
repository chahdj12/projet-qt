#include "secdialog.h"
#include "ui_secdialog.h"
#include "employe.h" // Include the employe header
#include "menu.h" // Include the menu header
#include <QMessageBox> // Include QMessageBox for error message

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    // Connecter le signal clicked du bouton loginButton au slot onLoginButtonClicked
    connect(ui->loginButton, &QPushButton::clicked, this, &SecDialog::onLoginButtonClicked);
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::onLoginButtonClicked() {
    // Récupérer les identifiants saisis par l'utilisateur
    QString id = ui->id_login->text();
    QString nom = ui->nom_login->text();

    // Vérifier que les champs ne sont pas vides
    if (id.isEmpty() || nom.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Veuillez saisir l'ID et le Nom.");
        return; // Sortir de la fonction si les champs sont vides
    }

    // Vérifier les identifiants dans la base de données
    employe emp;
    emp = emp.rechercherParId(id.toInt());

    // Vérifier si l'employé existe et que le nom correspond
    if (!emp.getname().isEmpty() && emp.getname() == nom) {
        // Les identifiants sont corrects, ouvrir le menu
        menu *menuWindow = new menu(this);
        menuWindow->show();
        this->hide();
    } else {
        // Les identifiants sont incorrects, afficher un message d'erreur
        QMessageBox::critical(this, "Erreur", "ID ou Nom incorrects.");
    }
}
