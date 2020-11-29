#ifndef BUTTON_ANSWER_H
#define BUTTON_ANSWER_H

#include <QPushButton>
#include <QString>
class Button_answer:public QPushButton
{
    bool isPlain;
protected:
    void virtual enterEvent(QEvent *e);
    void virtual leaveEvent(QEvent *e);

public:
    Button_answer(QWidget *parent);
    bool isChosen(void){return !isPlain;}
    void setPlain(void);
    void setOver(void);
    void setChosen(void);
    void setFault(void);
    void setRight(void);
};

#endif // BUTTON_ANSWER_H
