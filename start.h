#ifndef START_H
#define START_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Start; }
QT_END_NAMESPACE

class Start : public QMainWindow
{
    Q_OBJECT

public:
    Start(QWidget *parent = nullptr);
    ~Start();

private slots:
    void on_button_login_clicked();

    void on_pushButton_clicked();

    void on_register_result(bool);
    void on_tableWidget_problem_set_doubleClicked(const QModelIndex &index);

    void on_button_return_clicked();

    void on_button_login_2_clicked();

    void on_button_confirm_clicked();

private:
    Ui::Start *ui;
};
#endif // START_H
