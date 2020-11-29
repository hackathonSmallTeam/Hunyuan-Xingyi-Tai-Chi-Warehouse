#include "users.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <algorithm>
Users::Users()
{
    QFile file(QString("../save/user.json"));
    file.open(QIODevice::ReadOnly);
    QJsonDocument qjd = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonArray arr = qjd.object()["users"].toArray();
    for(int i=0;i<arr.size();i++){
        User tmp;
        QJsonObject obj = arr[i].toObject();
        tmp.uid = obj["uid"].toInt();
        tmp.name = obj["userName"].toString();
        tmp.password = obj["userName"].toString();
        tmp.face = obj["face"].toString();

        QJsonArray solvedList = obj["finishedProblem"].toArray();
        for(int j=0;j<solvedList.size();j++){
            QJsonObject tmpP = solvedList[j].toObject();
            Solved oneof;
            oneof.lid = tmpP["lid"].toInt();
            oneof.time = tmpP["time"].toInt();

            QJsonArray plist  = tmpP["pid"].toArray();
            for(int k=0;k<plist.size();k++)
                oneof.pids.insert(plist[k].toInt());
            tmp.xp += plist.size();
            tmp.solved.push_back(oneof);
        }
        list.push_back(tmp);
    }
}

User& Users::operator[](quint16 uid){
    for(auto &ele : this->list)
        if(ele.uid == uid)
            return ele;
    return emptyUser;
}

quint16 Users::login(QString name, QString password){
    for(const auto &ele : this->list)
        if(ele.name == name && ele.password == password)
            return ele.uid;
}

void Users::save(void){
    QFile file(QString("../save/user.json"));
    file.open(QIODevice::WriteOnly);

    QJsonDocument jdoc;
    QJsonObject doc;
    QJsonArray list;
    QJsonObject user;
    QJsonObject pros;
    for(const auto &u : this->list){
        user["uid"] = u.uid;
        user["userName"] = u.name;
        user["password"] = u.password;
        user["face"] = u.face;
        QJsonArray plist;
        for(const auto & ps:u.solved){
            pros["lid"] = ps.lid;
            pros["time"] = (qint32)ps.time;
            QJsonArray pids;
            for(const auto &pps : ps.pids)
                pids.append(pps);
            pros["pid"] = pids;
            plist.append(pros);
        }
        user["finishedProblem"] = plist;
        list.append(user);
    }
    doc["users"] = list;
    jdoc.setObject(doc);
    file.write(jdoc.toJson(QJsonDocument::Indented));
    file.close();
}
