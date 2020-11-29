#include "problems.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
Problems::Problems()
{

}
bool Problems::readProblemSet(quint8 lid){
    list.clear();

    QFile file(QString("../Hunyuan-Xingyi-Tai-Chi-Warehouse/save/libraries/library%1.json").arg(lid));
    file.open(QIODevice::ReadOnly);
    QJsonDocument qjd = QJsonDocument::fromJson(file.readAll());
    file.close();
    QJsonObject obj = qjd.object();

    this->lid =  obj["lid"].toInt();
    this->name = obj["libraryName"].toString();
    this->abstract = obj["abstract"].toString();
    QJsonArray problems = obj["problems"].toArray();
    for(int i=0;i<problems.count();i++){
        QJsonObject pobj(problems[i].toObject());
        Problem p;
        p.pid = pobj["pid"].toInt();
        p.stem = pobj["stem"].toString();
        p.answer = pobj["anwser"].toInt();
        QJsonArray options = pobj["options"].toArray();
        for(int j=0;j<options.size();j++)
            p.options[j] = options[j].toString();
        this->list.push_back(p);
    }
    return true;
}
