#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMdiArea>
#include <QWidget>
#include <QSignalMapper>
#include <QFileDialog>
#include <QMdiSubWindow>
#include <QTextStream>

#include "mdichild.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    //QMdiArea* mdiArea;

    MdiChild* createMDIChild(QString title);

    QSignalMapper* windowMapper;
    QString windowsText;

};

#endif // MAINWINDOW_H
