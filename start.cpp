#include "start.h"
#include "ui_start.h"
#include <QDebug>
#include "register_widget.h"
Start::Start(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Start)
{
    ui->setupUi(this);
    this->setWindowTitle(" ");
    this->ui->tableWidget_problem_set->horizontalHeader()->hide();
    this->ui->tableWidget_problem_set->setFrameShape(QFrame::NoFrame);
    this->ui->tableWidget_problem_set_2->horizontalHeader()->hide();
    this->ui->tableWidget_problem_set_2->setFrameShape(QFrame::NoFrame);
    //设置白色背景
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, Qt::white);
    this->setPalette(pal);

    //添加题集
    for (int i=0;i<3;i++) {
        QTableWidgetItem *icon = new QTableWidgetItem(QIcon(":/resource/素材_题库.png"),"强制下线");
        icon->setFlags(Qt::ItemIsEnabled);
        ui->tableWidget_problem_set->insertRow(i);
        ui->tableWidget_problem_set->setItem(i, 0, icon);
    }

    //建立答题按钮控制
    connect(ui->button_answer_0,&Button_answer::clicked,ui->button_answer_1,&Button_answer::setPlain);
    connect(ui->button_answer_0,&Button_answer::clicked,ui->button_answer_2,&Button_answer::setPlain);
    connect(ui->button_answer_0,&Button_answer::clicked,ui->button_answer_3,&Button_answer::setPlain);

    connect(ui->button_answer_1,&Button_answer::clicked,ui->button_answer_0,&Button_answer::setPlain);
    connect(ui->button_answer_1,&Button_answer::clicked,ui->button_answer_2,&Button_answer::setPlain);
    connect(ui->button_answer_1,&Button_answer::clicked,ui->button_answer_3,&Button_answer::setPlain);

    connect(ui->button_answer_2,&Button_answer::clicked,ui->button_answer_0,&Button_answer::setPlain);
    connect(ui->button_answer_2,&Button_answer::clicked,ui->button_answer_1,&Button_answer::setPlain);
    connect(ui->button_answer_2,&Button_answer::clicked,ui->button_answer_3,&Button_answer::setPlain);

    connect(ui->button_answer_3,&Button_answer::clicked,ui->button_answer_0,&Button_answer::setPlain);
    connect(ui->button_answer_3,&Button_answer::clicked,ui->button_answer_1,&Button_answer::setPlain);
    connect(ui->button_answer_3,&Button_answer::clicked,ui->button_answer_2,&Button_answer::setPlain);
}

Start::~Start()
{
    delete ui;
}


void Start::on_button_login_clicked()
{
    on_register_result(true);
}

void Start::on_pushButton_clicked()
{
    auto *widget = new Register_widget;
    widget->setWindowModality(Qt::ApplicationModal);
    widget->show();
    connect(widget,&Register_widget::isSuccess,this, &Start::on_register_result);
    connect(widget,&Register_widget::isSuccess,[widget](){delete widget;});
}

void Start::on_register_result(bool result){
    if(result)
        ui->mainWidget->setCurrentIndex(1);
    else
        ui->mainWidget->setCurrentIndex(0);
}

void Start::on_tableWidget_problem_set_doubleClicked(const QModelIndex &index)
{
    ui->widget_problem_info->setCurrentIndex(1);
}

void Start::on_button_return_clicked()
{
    ui->widget_problem_info->setCurrentIndex(0);
}

void Start::on_button_confirm_clicked()
{
    ui->label_question->setText("next question");
}
