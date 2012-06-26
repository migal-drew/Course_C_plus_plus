#ifndef MDICHILD_H
#define MDICHILD_H

#endif // MDICHILD_H

#include <QTextEdit>
#include <QToolBar>

class MdiChild : public QTextEdit
{
    Q_OBJECT

public:
    MdiChild();
    void setTextInEdit(QString str);
    QString getID();
    void setID(const QString ID);
    bool saveAs();
    bool save();
    bool saveFile(const QString &nameFile);
    QString getFilePath();
    void setCurrentFile(const QString &fileName);
    QString userFriendlyCurrentFile();

signals:

public slots:

private:
    QString ID;
    QString curFile;
    bool isUntitled;
};
