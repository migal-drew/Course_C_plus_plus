#include "subjects.h"

Subjects::Subjects()
{
    _dictionary = new QMap<int, QString>();
}

Subjects::~Subjects()
{

}

int Subjects::addSubj(QString subj)
{
    /*
    QMapIterator<int, QString> i = _dictionary->const_iterator();
    while (i.hasNext())
    {
        i.next();
        i.key();
        i.value();
    }
    */
    //subj = "";
    return 0;
}
