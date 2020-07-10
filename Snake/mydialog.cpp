#include "mydialog.h"
#include "snake.h"

MyDialog::MyDialog(QWidget * parent) : QDialog(parent)
{
    score = new QLabel;
    text = new QLabel;
    retry = new QPushButton;
    leave = new QPushButton;
    lay = new QGridLayout;
    this->parent = parent;

    letter_size.setPixelSize(200);

    score->setFont(letter_size);
    text->setFont(letter_size);

    letter_size.setPixelSize(180);

    leave->setFont(letter_size);
    retry->setFont(letter_size);


    text->setText("YOU ARE DEAD");
    retry->setText("RESTART");
    leave->setText("LEAVE");








    connect(retry,SIGNAL(clicked()),this,SLOT(RestartClicked()));
    connect(leave,SIGNAL(clicked()),this,SLOT(LeaveClicked()));



    lay->addWidget(text);
    lay->addWidget(score);
    lay->addWidget(retry);
    lay->addWidget(leave);


    setLayout(lay);

}

void MyDialog::RestartClicked()
{
  parent->close();
  parent = new Snake;

  parent->showFullScreen();



}

void MyDialog::Score()
{
 score_num++;
 emit Change(score_num);
}

void MyDialog::ChangeLabel(int a)
{
    QString b("YOUR SCORE: ");



    QString c;
    c.setNum(a);



    score->setText(b + c);
}

void MyDialog::LeaveClicked()
{
   parent->close();
}
