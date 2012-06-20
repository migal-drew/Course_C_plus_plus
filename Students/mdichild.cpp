#include "mdichild.h"
#include <QtCore>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>

MdiChild::MdiChild()
{
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;

}

void MdiChild::setTextInEdit(QString str) {
    setPlainText(str);
}

QString MdiChild::getID() {
    return ID;
}

void MdiChild::setID(const QString ID) {
    this->ID = ID;
}

bool MdiChild::saveAs() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    curFile);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

bool MdiChild::save() {
    if (isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MdiChild::saveFile(const QString& nameFile) {
    QFile file(nameFile);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("MDI"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(nameFile)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(nameFile);
    return true;
}

void MdiChild::setCurrentFile(const QString &fileName) {
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]");
}

QString MdiChild::userFriendlyCurrentFile() {
    return strippedName(curFile);
}

QString MdiChild::strippedName(const QString &fullFileName) {
    return QFileInfo(fullFileName).fileName();
}

QString MdiChild::getFilePath() {
    return curFile;
}

