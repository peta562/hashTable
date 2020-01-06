#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "associativearr.h"
#include <QtGui>

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
    void generate();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
