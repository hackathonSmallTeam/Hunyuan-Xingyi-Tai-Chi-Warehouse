#ifndef PROBLEMS_H
#define PROBLEMS_H
#include <QString>
#include <QVector>
struct Problem{
    quint8 pid;
    quint8 answer;
    QString stem;
    QString options[4];
};

class Problems
{
    quint8 lid;
    QString name;
    QString abstract;
    QVector<Problem> list;
public:
    Problems();
    Problem operator[](quint8 pid){return list[pid];}
    bool readProblemSet(quint8 lid);
    QString getName(void){return name;}
    QString getAbstract(void){return abstract;}
    quint8 getNum(void){return list.size();}
    quint8 getlid(void){return lid;}
};

#endif // PROBLEMS_H
