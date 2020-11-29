#include "finished.h"
#include "ui_finished.h"
#include <QString>
Finished::Finished(quint16 right, quint16 total, quint64 time, QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Finished)
{
    ui->setupUi(this);

    QGraphicsView *  stars[5] = {ui->star_1,ui->star_2,ui->star_3,ui->star_4,ui->star_5};

    ui->label_progress->setText(QString("%1").arg(right*100/total));
    quint8 fullStar = right/20;
    int i=fullStar;
    if(right%20 >= 10)
        stars[i++]->setStyleSheet("border-image: url(:/resource/素材_五角星半.png);");
    for(; i<5;i++)
        stars[i]->setStyleSheet("border-color: #FFFFFF;"
                                "border : none;");

    ui->label_name->setText(name);
    QString mess = QString("在%1道题中你答对%2道，共用时%3秒").arg(total).arg(right).arg(time);
    ui->label_mess->setText(mess);
    //设置白色背景
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, Qt::white);
    this->setPalette(pal);

}

Finished::~Finished()
{
    delete ui;
}

void Finished::on_button_login_2_clicked()
{
    emit again();
}

void Finished::on_button_login_clicked()
{
    emit back();
}

void Finished::closeEvent(QCloseEvent *e) {
    emit close();
    QWidget::closeEvent(e);
}
