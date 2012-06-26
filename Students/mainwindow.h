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
#include <QCheckBox>
#include <QtGui>

#include "mdichild.h"
#include "student.h"
#include "subjects.h"
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Subjects &getSubjects();

private slots:
    void on_actionOpen_triggered();

    void on_actionClose_triggered();

    void on_actionClose_All_triggered();

    void on_actionExit_triggered();

    void on_actionSearch_triggered();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();



    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

private:
    Ui::MainWindow *ui;

    MdiChild* getActiveMDIChild();
    int containsStudent(QString name);

public slots:
    void onReceive(QList<int>);

private:
    Subjects _subjs;
    QList<Student*> _students;
    Dialog *d;
};

#endif // MAINWINDOW_H
