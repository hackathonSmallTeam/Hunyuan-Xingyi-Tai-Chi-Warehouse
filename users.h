#ifndef USERS_H
#define USERS_H
#include <QVector>
#include <QString>
#include <QSet>
struct Solved{
    quint8 lid;
    QSet<quint8> pids;
    quint64 time;
};
struct User{
    quint16 uid;
    quint16 xp = 0;
    QString name;
    QString password;
    QString face;
    QVector<Solved> solved;
};

class Users{
    QVector<User> list;
    User emptyUser;
public:
    Users();
    quint16 login(QString name, QString password);
    User& operator[](quint16 uid);
    void save(void);
};

#endif // USERS_H
