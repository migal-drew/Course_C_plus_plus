#ifndef SUBJECTS_H
#define SUBJECTS_H

#include <QMap>
#include <QString>

class Subjects
{
public:
    Subjects();
    ~Subjects();

    //Returns ID of inserted subject
    int addSubj(QString subj);
    void removeSubj(QString subj);
    void removeSubj(int id);
    void clear();
    QString getSubj(int id);
    int getID(QString subj);

private:
    QMap<int, QString>* _dictionary;
};

#endif // SUBJECTS_H
