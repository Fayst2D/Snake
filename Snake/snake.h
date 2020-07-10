#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QDialog>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include "mydialog.h"









class Snake : public QWidget
{
    Q_OBJECT

public:
    Snake(QWidget *parent = nullptr);
    void Restart();

private:

    void Eat();
    void Dead();
    void keyPressEvent(QKeyEvent *key);
    double radius,j = 0,x = 0,y = 0,speed;
    int score = 0;

    MyDialog *death;
    QGraphicsScene *field;
    QGraphicsView *view;
    QGridLayout *lay;
    QTimer *time;
    QKeyEvent* key1;
    QString dir;
    QVector<QGraphicsRectItem*> tail;
    QGraphicsRectItem *apple;
    QString str;

    int counter = 1;

    QDialog a;





 public slots:
    void TimeOut();
    void Leave();
    void Open();

signals:


};










#endif // SNAKE_H
