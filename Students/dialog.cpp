#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    signalMapper = new QSignalMapper(this);
    chBoxes = new QList<QCheckBox*>();
    this->setModal(true);
    subjIDs.clear();

    if (parent)
        if (MainWindow *mw = qobject_cast<MainWindow*>(parent))
            this->sbjs = mw->getSubjects();

    this->fill(this->sbjs);

    /*
    QGridLayout *ltOK = new QGridLayout(this->ui->btn_ok);
    QGridLayout *ltCancel = new QGridLayout(this->ui->btn_cancel); // The layout

    //ltOK->setContentsMargin(10,10,10,10);
    //ltCancel->setContentsMargin(10,10,10,10);
    ltOK->addWidget(this->ui->btn_ok, 1, 1);
    ltCancel->addWidget(this->ui->btn_cancel, 1, 1);
    ltOK->setRowStretch(0, 1);
    ltCancel->setRowStretch(0, 1);
    ltOK->setColumnStretch(0, 1);
    ltCancel->setColumnStretch(0, 1);
    */

}

void Dialog::fill(Subjects &subj)
{
    for (int i = 0; i < subj.size(); i++)
    {
        QCheckBox *chBx = new QCheckBox();
        chBx->setText(subj[i]);
        this->ui->gridLayout->addWidget(chBx, i, 1, Qt::AlignLeft);
        this->chBoxes->append(chBx);
    }
}

Dialog::~Dialog()
{
    delete ui;
    delete signalMapper;
}

void Dialog::on_btn_cancel_clicked()
{
    this->close();
}

void Dialog::on_btn_ok_clicked()
{
    this->subjIDs.clear();

    for (int i = 0; i < chBoxes->size(); i++)
    {
        if ((*chBoxes)[i]->isChecked())
            this->subjIDs.append(i);
    }
    emit onClose(subjIDs);
    this->close();
}
