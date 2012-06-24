#ifndef STUDENT_H
#define STUDENT_H

#include <QVector>
#include <QString>
class Student
{
public:
    Student();
    ~Student();

private:
    QString _name;
    QVector<int> _subjects;

public:
    QString getName();
    void setName(QString s);
    QVector<int> getSubjects();
    void setSubjects(QVector<int> v);
    void addSubjects(QVector<int> v);
    void addSubj(int id);
    void removeSubj(int id);
    void clearSubjects();
    bool learnSubj(int id);
};

#endif // STUDENT_H
