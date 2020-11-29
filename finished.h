#ifndef FINISHED_H
#define FINISHED_H

#include <QWidget>

namespace Ui {
class Finished;
}

class Finished : public QWidget
{
    Q_OBJECT

public:
    explicit Finished(quint16 right, quint16 total, quint64 time, QString name, QWidget *parent = nullptr);
    ~Finished();
protected:
    void virtual closeEvent(QCloseEvent *e)override ;
signals:
    void again(void);
    void back(void);
    void close(void);
private slots:
    void on_button_login_2_clicked();

    void on_button_login_clicked();

private:
    Ui::Finished *ui;
};

#endif // FINISHED_H
