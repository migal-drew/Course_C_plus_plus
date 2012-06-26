#include "subjects.h"

#include <QMessageBox>

Subjects::Subjects()
{
    _dictionary = new QMap<int, QString>();
}

Subjects::~Subjects()
{
    delete _dictionary;
}

int Subjects::addSubj(QString subj)
{
    int pos = -1;
    QMapIterator<int, QString> i(*_dictionary);
    while (i.hasNext())
    {
        i.next();
        if (i.key() > pos)
            pos = i.key();
        if (i.value().compare(subj) == 0)
            return i.key();
    }
    _dictionary->insert(++pos, subj);
    //QMessageBox::information(0, "ADDED to DICT", subj);
    return pos;
}

void Subjects::clear()
{
    _dictionary->clear();
}

QString Subjects::getSubj(int id)
{
    if (id < 0 || id >= this->size())
        return NULL;

    QMapIterator<int, QString> i(*_dictionary);
    while (i.hasNext())
    {
        i.next();
        int k = i.key();
        if (k == id)
            return i.value();
    }
}

int Subjects::size()
{
    return _dictionary->size();
}

int Subjects::getID(QString subj)
{
    QMapIterator<int, QString> i(*_dictionary);
    while (i.hasNext())
    {
        i.next();
        if (i.value().compare(subj) == 0)
            return i.key();
    }

    return -1;
}

QString Subjects::operator [](int id)
{
    return this->getSubj(id);
}
