#ifndef REGISTER_WIDGET_H
#define REGISTER_WIDGET_H

#include <QWidget>

namespace Ui {
class Register_widget;
}

class Register_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Register_widget(QWidget *parent = nullptr);
    ~Register_widget();

signals:
    void isSuccess(bool);

private slots:
    void on_button_login_clicked();

    void on_button_login_2_clicked();

private:
    Ui::Register_widget *ui;
};

#endif // REGISTER_WIDGET_H
