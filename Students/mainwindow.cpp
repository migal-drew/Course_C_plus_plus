#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->mdiArea);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, "Open a file...", "", "File(*.txt)");
    QFile file(fileName);
    QString data = "";

    try
    {
        //QMessageBox::information(0, "Data", "try");
        if (!fileName.isEmpty())
        {
            if (file.open(QFile::ReadOnly))
            {
                //QMessageBox::information(0, "Data", "file open");
                QTextStream in(&file);

                while (!in.atEnd())
                {
                    QString line = in.readLine();
                    data.append(line + "\n");
                }
            }
        }
    }
    catch (int e)
    {
        file.close();
    }

    MdiChild* mc = new MdiChild();
    mc->setID(fileName);
    mc->setCurrentFile(fileName);
    mc->setTextInEdit(data);

    ui->mdiArea->addSubWindow(mc);

    mc->show();
}

void MainWindow::on_actionClose_triggered()
{
    this->ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_actionClose_All_triggered()
{
    QList<QMdiSubWindow*> list = this->ui->mdiArea->subWindowList();
    for (int i = 0; i < list.size(); i++)
        list[i]->close();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionSearch_triggered()
{
    _students.clear();
    _subjs.clear();

    QString data = "";
    //QMessageBox::information(0, "Data", "all clear");
    try
    {
        if (MdiChild *mc = this->getActiveMDIChild())
        {
            data = mc->toPlainText();
            //QMessageBox::information(0, "Data", "Start parse");
            QStringList list = data.split("\n");
            for (int i = 0; i < list.size(); i++)
            {
                QStringList info = list.at(i).split(" ");
                if (info.size() == 2)
                {
                    int pos = this->containsStudent(info[0]);
                    if (pos != -1)
                    {
                        Student *s = this->_students[pos];
                        int subjID = _subjs.addSubj(info[1]);
                        s->addSubj(subjID);
                    }
                    else
                    {
                        Student *s  = new Student();
                        s->setName(info[0]);
                        int subjID = _subjs.addSubj(info[1]);
                        s->addSubj(subjID);
                        _students.append(s);
                    }
                }

            }

            d = new Dialog(this);
            connect(d, SIGNAL(onClose(QList<int>)),
                    this, SLOT(onReceive(QList<int>)));
            d->show();
        }
    }
    catch (int e)
    {

    }
}

int MainWindow::containsStudent(QString name)
{
    for (int i = 0; i < _students.size(); i++)
        if (_students.at(i)->getName().compare(name) == 0)
            return i;

    return -1;
}

void MainWindow::on_actionNew_triggered()
{
    MdiChild* mc = new MdiChild();
    mc->setWindowTitle("Untitled");
    this->ui->mdiArea->addSubWindow(mc);
    mc->show();
}

MdiChild* MainWindow::getActiveMDIChild()
{
    QMdiSubWindow* activeSubWin = this->ui->mdiArea->activeSubWindow();
    if (activeSubWin)
        return qobject_cast<MdiChild*>(activeSubWin->widget());

    return NULL;
}

void MainWindow::on_actionSave_triggered()
{
    MdiChild* mc = this->getActiveMDIChild();
    mc->save();
}

void MainWindow::on_actionSave_as_triggered()
{
    MdiChild* mc = this->getActiveMDIChild();
    mc->saveAs();
}

Subjects& MainWindow::getSubjects()
{
    return _subjs;
}

void MainWindow::onReceive(QList<int> idList)
{
    if (d != NULL)
    {
        //QList<int> idList = d->subjIDs;
        QString strRes;
        for (int i = 0; i < idList.size(); i++)
            for (int j = 0; j < _students.size(); j++)
                if (_students[j]->learnSubj(idList[i]))
                    strRes.append(_students[j]->getName()
                                  + "\n");

        MdiChild *winRes = new MdiChild();
        winRes->setWindowTitle("Result");
        winRes->setTextInEdit(strRes);
        this->ui->mdiArea->addSubWindow(winRes);
        winRes->show();
    }
}

void MainWindow::on_actionUndo_triggered()
{
    MdiChild *mc = this->getActiveMDIChild();
    if (mc)
        mc->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    MdiChild *mc = this->getActiveMDIChild();
    if (mc)
        mc->redo();
}

void MainWindow::on_actionCopy_triggered()
{
    MdiChild *mc = this->getActiveMDIChild();
    if (mc)
        mc->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    MdiChild *mc = this->getActiveMDIChild();
    if (mc)
        mc->paste();
}
