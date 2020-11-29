#include "button_answer.h"
#include <QDebug>
Button_answer::Button_answer(QWidget *parent)
    :QPushButton(parent),
      isPlain(true)
{
    connect(this,&QPushButton::clicked,this,&Button_answer::setChosen);
    connect(this,&QPushButton::clicked,[this](){isPlain=false;});
    this->setPlain();
}
void Button_answer::setPlain(void){
    isPlain = true;
    this->setStyleSheet("QPushButton "
                        "{background-color : #E6E6E6;"
                        "border : none;"
                        "color : #333333;"
                        "font-family: \"Microsoft YaHei\";"
                        "font-size:15px;}");
}
void Button_answer::setOver(void){
    this->setStyleSheet("QPushButton:hover "
                        "{background-color : #F2F2F2;"
                        "border : none;"
                        "color : #000000;"
                        "font-family: \"Microsoft YaHei\";"
                        "font-size:15px;}");
}
void Button_answer::setChosen(void){
    this->setStyleSheet("QPushButton "
                        "{background-color : #27C7B7;"
                        "border : none;"
                        "color : #FFFFFF;"
                        "font-family: \"Microsoft YaHei\";"
                        "font-size:15px;}");
}
void Button_answer::setFault(void){
    this->setStyleSheet("QPushButton "
                        "{background-color : #ED5156;"
                        "border : none;"
                        "color : #FFFFFF;"
                        "font-family: \"Microsoft YaHei\";"
                        "font-size:15px;}");
}

void Button_answer::setRight(void){
    this->setStyleSheet("QPushButton "
                        "{background-color : #57D469;"
                        "border : none;"
                        "color : #FFFFFF;"
                        "font-family: \"Microsoft YaHei\";"
                        "font-size:15px;}");
}

void Button_answer::enterEvent(QEvent *e){
    if(isPlain)
        this->setOver();
    QWidget::enterEvent(e);
}
void Button_answer::leaveEvent(QEvent *e){
    if(isPlain)
        this->setPlain();
    QWidget::leaveEvent(e);
}
