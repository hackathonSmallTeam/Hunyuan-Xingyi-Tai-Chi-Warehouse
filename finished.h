#ifndef FINISHED_H
#define FINISHED_H

#include <QWidget>

namespace Ui {
class Finished;
}

class Finished : public QWidget
{
    Q_OBJECT

public:
    explicit Finished(QWidget *parent = nullptr);
    ~Finished();

private:
    Ui::Finished *ui;
};

#endif // FINISHED_H
