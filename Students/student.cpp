#include "student.h"

Student::Student()
{
    _name = "";
    //_subjects = new QVector<int>();
}

Student::~Student()
{

}

QString Student::getName()
{
    return _name;
}

void Student::setName(QString s)
{
    _name = s;
}

QVector<int> Student::getSubjects()
{
    return _subjects;
}

void Student::setSubjects(QVector<int> v)
{
    this->clearSubjects();
    this->addSubjects(v);
}

void Student::addSubj(int id)
{
    _subjects.push_back(id);
}

void Student::addSubjects(QVector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        _subjects.push_back(v.at(i));
}

bool Student::learnSubj(int id)
{
    for (int i = 0; i < _subjects.size(); i++)
        if (_subjects.at(i) == id)
            return true;

    return false;
}

void Student::removeSubj(int id)
{
    for (int i = 0; i < _subjects.size(); i++)
        if (_subjects.at(i) == id)
        {
            _subjects.remove(i);
            return;
        }
}

void Student::clearSubjects()
{
    _subjects.clear();
}
