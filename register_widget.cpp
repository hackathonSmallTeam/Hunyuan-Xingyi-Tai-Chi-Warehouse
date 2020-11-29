#include "register_widget.h"
#include "ui_register_widget.h"

Register_widget::Register_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register_widget)
{
    ui->setupUi(this);

    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, Qt::white);
    this->setPalette(pal);
}

Register_widget::~Register_widget()
{
    delete ui;
}

void Register_widget::on_button_login_clicked()
{
    ui->label_password_3->setText("当前功能暂未开放");
//    emit isSuccess(true);
}

void Register_widget::on_button_login_2_clicked()
{
    emit isSuccess(false);
}
