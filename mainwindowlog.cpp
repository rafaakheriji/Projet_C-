#include "mainwindowlog.h"
#include "ui_mainwindowlog.h"

MainWindowlog::MainWindowlog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowlog)
{
    ui->setupUi(this);
}

MainWindowlog::~MainWindowlog()
{
    delete ui;
}
