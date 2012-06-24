#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->mdiArea = new QMdiArea();
    this->setCentralWidget(ui->mdiArea);
    //windowMapper = new QSignalMapper(this);
    //connect(windowMapper, SIGNAL(mapped(QWidget*)),
      //      this, SLOT(setActivSubWindows(QWidget*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

MdiChild* MainWindow::createMDIChild(QString title) {
    MdiChild* mdi = new MdiChild;

    if (title == "") {
        title = QString::number(this->ui->mdiArea->subWindowList().count());
        mdi->setWindowTitle(title);
        mdi->setID(title);
    } else {
        mdi->setWindowTitle(title);
        mdi->setID(title);
    }
    this->ui->mdiArea->addSubWindow(mdi);

    return mdi;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, "Open a file...", "", "File(*.txt)");
    QFile file(fileName);
    QString data;

    try
    {
        if (fileName.isEmpty())
        {
            if (file.open(QFile::ReadOnly))
            {
                QTextStream in(&sfile);

                while (in.atEnd())
                {
                    //QString line = in.readLine();
                    //QStringList = line.split(" ");
                    data.append(in.readLine());
                }

            }
        }
    }
    catch (int e)
    {
        QMessageBox::information(0, "Error", "Unhandled error in txt file");
        file.close();
    }

    MdiChild* mc = new MdiChild();
    mc->setID("My first ID");
    mc->setTextInEdit(data);

    ui->mdiArea->addSubWindow((QWidget*)mc);

    mc->show();
    /*
    QMdiSubWindow* subW = new QMdiSubWindow(this);
    subW->setFixedSize(300, 400);
    ui->mdiArea->addSubWindow(subW);
    subW->show();
    */
}


