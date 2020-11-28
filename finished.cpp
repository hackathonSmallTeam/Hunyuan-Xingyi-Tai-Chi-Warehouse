#include "finished.h"
#include "ui_finished.h"

Finished::Finished(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Finished)
{
    ui->setupUi(this);

    //设置白色背景
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, Qt::white);
    this->setPalette(pal);

}

Finished::~Finished()
{
    delete ui;
}
