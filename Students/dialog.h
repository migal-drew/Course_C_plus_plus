#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QSignalMapper>
#include <QMessageBox>

#include "subjects.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    QList<int> subjIDs;
    Subjects sbjs;
    
private slots:
    void on_btn_cancel_clicked();

    void on_btn_ok_clicked();

signals:
    void onClose(QList<int>);

private:
    Ui::Dialog *ui;

    void fill(Subjects &subj);

    QSignalMapper* signalMapper;
    QList<QCheckBox*> *chBoxes;
};

#endif // DIALOG_H
