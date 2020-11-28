#include "button_answer.h"

Button_answer::Button_answer(QWidget *parent)
    :QPushButton(parent)
{
    this->setPlain();
}
void Button_answer::setPlain(void){
    this->setStyleSheet("QPushButton "
                        "{border-color : #E6E6E6;"
                        "color : #333333}");
}
void Button_answer::setOver(void){
    this->setStyleSheet("QPushButton "
                        "{border-color : #F2F2F2;"
                        "color : #000000}");
}
void Button_answer::setChosen(void){
    this->setStyleSheet("QPushButton "
                        "{border-color : #27C7B7;"
                        "color : #FFFFFF}");
}
void Button_answer::setFault(void){
    this->setStyleSheet("QPushButton "
                        "{border-color : #ED5156;"
                        "color : #FFFFFF}");
}

void Button_answer::setRight(void){
    this->setStyleSheet("QPushButton "
                        "{border-color : #57D469;"
                        "color : #FFFFFF}");
}
