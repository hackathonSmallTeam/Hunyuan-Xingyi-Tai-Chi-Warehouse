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

private:
    Ui::Register_widget *ui;
};

#endif // REGISTER_WIDGET_H
