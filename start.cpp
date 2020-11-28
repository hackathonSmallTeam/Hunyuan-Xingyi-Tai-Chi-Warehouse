#include "start.h"
#include "ui_start.h"
#include <QDebug>
Start::Start(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Start)
{
    ui->setupUi(this);
    this->setWindowTitle(" ");
    this->ui->tableWidget_problem_set->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->ui->tableWidget_problem_set->horizontalHeader()->hide();
    this->ui->tableWidget_problem_set->setFrameShape(QFrame::NoFrame);
    //设置白色背景
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, Qt::white);
    this->setPalette(pal);

    //
}

Start::~Start()
{
    delete ui;
}


void Start::on_button_login_clicked()
{
    qDebug() << "login clicked\n" ;
}
