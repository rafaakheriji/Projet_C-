#ifndef MAINWINDOWLOG_H
#define MAINWINDOWLOG_H

#include <QMainWindow>

namespace Ui {
class MainWindowlog;
}

class MainWindowlog : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowlog(QWidget *parent = nullptr);
    ~MainWindowlog();

private:
    Ui::MainWindowlog *ui;
};

#endif // MAINWINDOWLOG_H
