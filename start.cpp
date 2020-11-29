#include "start.h"
#include "ui_start.h"
#include <QTime>
#include "register_widget.h"
#include"finished.h"
Start::Start(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Start)
{
    ui->setupUi(this);
    //设置tableweidget
    this->setWindowTitle(" ");
    this->ui->tableWidget_problem_set->setFocusPolicy(Qt::NoFocus);
    this->ui->tableWidget_problem_set->horizontalHeader()->hide();
    this->ui->tableWidget_problem_set->setFrameShape(QFrame::NoFrame);
    this->ui->tableWidget_problem_set_2->setFocusPolicy(Qt::NoFocus);
    this->ui->tableWidget_problem_set_2->horizontalHeader()->hide();
    this->ui->tableWidget_problem_set_2->setFrameShape(QFrame::NoFrame);
    //设置白色背景
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, Qt::white);
    this->setPalette(pal);

    //添加题集
    for (int i=0;i<2;i++) {
        Problems ps;
        ps.readProblemSet(i);
        QTableWidgetItem *icon = new QTableWidgetItem(QIcon(":/resource/素材_题库.png"),ps.getName());
        icon->setFlags(Qt::ItemIsEnabled);
        ui->tableWidget_problem_set->insertRow(i);
        ui->tableWidget_problem_set->setItem(i, 0, icon);
    }

    //建立答题按钮控制
    connect(ui->button_answer_0,&Button_answer::clicked,ui->button_answer_1,&Button_answer::setPlain);
    connect(ui->button_answer_0,&Button_answer::clicked,ui->button_answer_2,&Button_answer::setPlain);
    connect(ui->button_answer_0,&Button_answer::clicked,ui->button_answer_3,&Button_answer::setPlain);
    connect(ui->button_answer_0,&Button_answer::clicked,[this](){
        ui->button_confirm->setEnabled(true);
        ui->button_confirm->setStyleSheet("background-color : rgb(39, 199, 183);"
                                          "font-family : \"Microsoft YaHei\";"
                                          "font-size : 15px;"
                                          "color : #FFFFFF;"
                                          "border : none;");
    });
    connect(ui->button_answer_1,&Button_answer::clicked,ui->button_answer_0,&Button_answer::setPlain);
    connect(ui->button_answer_1,&Button_answer::clicked,ui->button_answer_2,&Button_answer::setPlain);
    connect(ui->button_answer_1,&Button_answer::clicked,ui->button_answer_3,&Button_answer::setPlain);
    connect(ui->button_answer_1,&Button_answer::clicked,[this](){
        ui->button_confirm->setEnabled(true);
        ui->button_confirm->setStyleSheet("background-color : rgb(39, 199, 183);"
                                          "font-family : \"Microsoft YaHei\";"
                                          "font-size : 15px;"
                                          "color : #FFFFFF;"
                                          "border : none;");
    });
    connect(ui->button_answer_2,&Button_answer::clicked,ui->button_answer_0,&Button_answer::setPlain);
    connect(ui->button_answer_2,&Button_answer::clicked,ui->button_answer_1,&Button_answer::setPlain);
    connect(ui->button_answer_2,&Button_answer::clicked,ui->button_answer_3,&Button_answer::setPlain);
    connect(ui->button_answer_2,&Button_answer::clicked,[this](){
        ui->button_confirm->setEnabled(true);
        ui->button_confirm->setStyleSheet("background-color : rgb(39, 199, 183);"
                                          "font-family : \"Microsoft YaHei\";"
                                          "font-size : 15px;"
                                          "color : #FFFFFF;"
                                          "border : none;");
    });
    connect(ui->button_answer_3,&Button_answer::clicked,ui->button_answer_0,&Button_answer::setPlain);
    connect(ui->button_answer_3,&Button_answer::clicked,ui->button_answer_1,&Button_answer::setPlain);
    connect(ui->button_answer_3,&Button_answer::clicked,ui->button_answer_2,&Button_answer::setPlain);
    connect(ui->button_answer_3,&Button_answer::clicked,[this](){
        ui->button_confirm->setEnabled(true);
        ui->button_confirm->setStyleSheet("background-color : rgb(39, 199, 183);"
                                          "font-family : \"Microsoft YaHei\";"
                                          "font-size : 15px;"
                                          "color : #FFFFFF;"
                                          "border : none;");
    });
}

Start::~Start()
{
    delete ui;
}


void Start::on_button_login_clicked()
{
    QString name(ui->lineEdit_name->text());
    QString password(ui->lineEdit_password->text());
    if(name=="" || password==""){
        ui->label_login_fault->setText("请输入完整用户名密码");
        return ;
    }
    auto uid = this->userList.login(name,password);
    user = userList[uid];
    if(user.name=="" && user.password==""){
        ui->label_login_fault->setText("用户名不存在或密码错误");
        return ;
    }
    ui->graphicsView_face->setStyleSheet(QString("border-image : url(../save/faces/img%1.jpg)").arg(uid));
    ui->label_user_name->setText(user.name);
    ui->label_xp->setText(QString("Lv %1\n经验：%2/80").arg(user.xp/80 + 1).arg(user.xp%80));
    ui->pushButton_progress_2->resize(user.xp%80*2,ui->pushButton_progress_2->height());
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
    problems.readProblemSet(index.row());
    ui->label_title->setText(problems.getName());

    rightNum=0;
    nowpid=0;
    setNextQuestion();
    nowpid++;
    ui->widget_problem_info->setCurrentIndex(1);
}

void Start::on_button_return_clicked()
{
    ui->widget_problem_info->setCurrentIndex(0);
}

void Start::on_button_confirm_clicked()
{
    static Button_answer* btns[4] = {ui->button_answer_0,ui->button_answer_1,ui->button_answer_2,ui->button_answer_3};
    Problem pro = problems[nowpid-1];
    for(int i=0;i<4;i++){
        if(pro.answer==i){
            btns[i]->setRight();
            rightNum++;
            user.solved[problems.getlid()].pids.insert(nowpid-1);
        }
        if(btns[i]->isChosen()){
            if(pro.answer!=i){
                btns[i]->setFault();
            }
        }
    }
    ui->button_confirm->setEnabled(false);
    ui->button_confirm->setStyleSheet("background-color : #E6E6E6;"
                                      "font-family : \"Microsoft YaHei\";"
                                      "font-size : 15px;"
                                      "color : #B3B3B3;"
                                      "border : none;");

    QTime time;
    time.start();
    while(time.elapsed() < 3000)             //等待时间流逝5秒钟
        QCoreApplication::processEvents();   //处理事件

    if(false == setNextQuestion()){
        auto *widget = new Finished(rightNum,problems.getNum(),user.solved[problems.getlid()].time,problems.getName());
        widget->setWindowModality(Qt::ApplicationModal);
        connect(widget,&Finished::again,[=](){
            rightNum=0;
            nowpid=0;
            setNextQuestion();
            nowpid++;
            ui->button_answer_0->setPlain();
            ui->button_answer_1->setPlain();
            ui->button_answer_2->setPlain();
            ui->button_answer_3->setPlain();
            delete widget;
        });
        connect(widget,&Finished::back,[=](){
            ui->widget_problem_info->setCurrentIndex(0);
            ui->button_answer_0->setPlain();
            ui->button_answer_1->setPlain();
            ui->button_answer_2->setPlain();
            ui->button_answer_3->setPlain();
            delete  widget;
        });
        connect(widget,&Finished::close,[=](){
            ui->widget_problem_info->setCurrentIndex(0);
            ui->button_answer_0->setPlain();
            ui->button_answer_1->setPlain();
            ui->button_answer_2->setPlain();
            ui->button_answer_3->setPlain();
        });
        widget->show();
        user.xp+=rightNum;
        ui->label_xp->setText(QString("Lv %1\n经验：%2/80").arg(user.xp/80 + 1).arg(user.xp%80));
        this->userList[user.uid] = user;
        userList.save();
    }
    else
        nowpid++;
}

bool Start::setNextQuestion(void){
    if(nowpid >= problems.getNum())
        return false;
    Problem p = problems[nowpid];
    ui->label_progress->setText(QString("%1/%2").arg(nowpid+1).arg(problems.getNum()));
    ui->label_question->setText(p.stem);
    ui->button_answer_0->setText(p.options[0]);
    ui->button_answer_0->setPlain();
    ui->button_answer_1->setText(p.options[1]);
    ui->button_answer_1->setPlain();
    ui->button_answer_2->setText(p.options[2]);
        ui->button_answer_2->setPlain();
    ui->button_answer_3->setText(p.options[3]);
        ui->button_answer_3->setPlain();
    return true;
}
