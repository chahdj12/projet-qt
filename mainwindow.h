#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "associations.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void navigateToPage();
    void toggleIconOnlyWidget();

    void on_pushButton_ajouter_clicked();

    void on_edit2_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_afficher_clicked();

    void on_view_2_clicked();

    void on_pushButton_2_clicked();

    void on_Boutton_rechecher_clicked();

private :
    Ui::MainWindow *ui;
    int findPageIndex(const QPushButton *button) const;
associations E ;
};
#endif // MAINWINDOW_H
