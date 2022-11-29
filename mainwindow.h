#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"avocat.h"
#include<QObject>
#include <QMainWindow>
#include<QPrinter>
#include<QTextDocument>
#include<QTextStream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_modifier_clicked();

    void on_pb_tri_clicked();

    void on_pb_rech_clicked();

    void on_pb_cal_clicked();

    void on_PDF_clicked();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Avocat A ;
};

#endif // MAINWINDOW_H
