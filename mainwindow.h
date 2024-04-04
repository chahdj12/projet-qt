#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "associations.h"
#include "notification.h"
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

   // void on_edit2_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_afficher_clicked();

    void on_view_2_clicked();

    void on_pushButton_2_clicked();

    //void on_Boutton_rechecher_clicked();

   // void on_valider_clicked();

    void on_comboBox_currentTextChanged(const QString &text);


    //void on_pushButton_clicked();

    void on_sort_clicked();

    void on_stat_clicked();
    void on_Button_emp_mois_clicked();


    //void on_pushButton_clicked();

    void on_progressBar_valueChanged(int value);

    void on_Boutton_rechecher_clicked();

    void on_la_chercher_id_cursorPositionChanged(int arg1, int arg2);

    void on_on_send_email_clicked();

    void on_don_clicked();

    void on_send_email_clicked();
    void insertCalendar() ;
    void on_calendarWidget_activated(const QDate &);


private :

     notification notif;
    Ui::MainWindow *ui;
    int findPageIndex(const QPushButton *button) const;
associations E ;
};
#endif // MAINWINDOW_H
