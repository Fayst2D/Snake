#include "snake.h"
#include <QTime>




Snake::Snake(QWidget *parent) : QWidget(parent)
{

    QTime random(0,0,0);
    qsrand(random.secsTo(QTime::currentTime()));




    this->setMinimumSize(1920,1080);


    death = new MyDialog(this);
    death->setModal(true);
    field = new QGraphicsScene(0,0,1800,1040,this);
    lay = new QGridLayout;
    view = new QGraphicsView(this);
    time = new QTimer;
    speed = 40;
    apple = new QGraphicsRectItem(40,40,40,40);
    apple->setBrush(QColor("red"));




    x = field->width()/2;
    y = field->height()/2;


    connect(time,SIGNAL(timeout()),this,SLOT(TimeOut()));


    field->setBackgroundBrush(QColor("black"));

    field->addItem(apple);
    apple->setPos((qrand()%(1720 /40))*40+40,(qrand()%(920/40)) * 40+40);
    for(int i(0);i < tail.size();i++)
    {
        if(apple->pos() == tail[i]->pos())
        {
            apple->setPos((qrand()%(1720 /40))*40+40,(qrand()%(920/40)) * 40+40);
        }
    }


    view->setScene(field);


    lay->addWidget(view);

    setLayout(lay);



}

void Snake::Restart()
{
    Snake a;
    this->deleteLater();
}

void Snake::Eat()
{
    int n = 1;

    if(counter == 1)
    {

        n = tail.size() - (tail.size()*2) + 1;
    }




  if(apple->pos() == tail[tail.size()-counter+n]->pos())
  {

      score++;


      apple->setPos((qrand()%(1720 /40))*40+40,(qrand()%(920/40)) * 40+40);

      QGraphicsRectItem* a = new QGraphicsRectItem(40,40,40,40);
      a->setBrush(QColor("white"));

      tail.push_back(a);

      tail[tail.size()-1]->setPen(QColor("white"));
      field->addItem(tail[tail.size()-1]);

      tail[tail.size()-1]->setPos(tail[tail.size()-2]->pos());
      if(counter != 1)
      {

          counter++;
      }

  }

}



void Snake::Dead()
{
    int n = 1;
    if(counter == 1)
    {

        n = tail.size() - (tail.size()*2) + 1;
    }

    if(tail[tail.size()-counter+n]->x() + 160 > width() || tail[tail.size()-counter+n]->x() < -80)
    {
        emit death->ChangeLabel(score);
        death->open();
        time->stop();
    }

    if(tail[tail.size()-counter+n]->y() + 120 > height()  || tail[tail.size()-counter+n]->y() < -40)
    {

        emit death->ChangeLabel(score);
        death->open(); 
        time->stop();

    }


    for(int i(0);i < tail.size();i++)
    {
        if (tail[tail.size()-counter+n]->pos() == tail[i]->pos())
        {
            if(tail[tail.size()-counter+n] != tail[i])
            {
                emit death->ChangeLabel(score);
                death->show();
                time->stop();

            }
        }
    }
}




void Snake::TimeOut()
{
    keyPressEvent(key1);
}

void Snake::Leave()
{
    close();
}

void Snake::Open()
{
    show();
}





void Snake::keyPressEvent(QKeyEvent *key)
{
  if(key->key() == Qt::Key_W || key->key() == Qt::Key_S || key->key() == Qt::Key_D || key->key() == Qt::Key_A)
  {
    if(j == 0.0)
    {
        key1 = new QKeyEvent(*key);

        double xchange = 0,ychange = 0;

        switch(key1->key())
        {

             case Qt::Key_W: ychange = speed; break;
             case Qt::Key_S: ychange = speed - (speed*2); break;
             case Qt::Key_A: xchange = speed; break;
             case Qt::Key_D: xchange = speed - (speed*2);break;
        }


        for(int i(0);i < 4;i++)
        {
            QGraphicsRectItem* a = new QGraphicsRectItem(40,40,40,40);
            a->setBrush(QColor("white"));

            tail.push_back(a);

            tail[i]->setPen(QColor("white"));
            field->addItem(tail[i]);
            tail[i]->setPos((960 + xchange * (i + 1)),(520 + ychange * (i + 1)));
        }


        x = 960;
        y = 520;

        y += ychange;
        x += xchange;



        time->start(50);
        j++;
    }
    else
    {

            str.setNum(key->key() - key1->key());
            if(str.toInt()<0)
            {
                str.setNum(str.toInt() * (-1));
            }


            if(str.contains(QRegExp("[4,3]")))
            {

            }
            else
            {
                key1 = new QKeyEvent(*key);


                switch(key->key())
                {
                case Qt::Key_W : y-=speed;break;
                case Qt::Key_A : x-=speed;break;
                case Qt::Key_S : y+=speed;break;
                case Qt::Key_D : x+=speed;break;
                }
                tail[tail.size()-counter]->setPos(x,y);
                counter++;


                if(counter > tail.size())
                {
                   counter = 1;
                }

                if(j == 3)
                {
                    Dead();

                }
                else
                {
                    j++;
                }

                   Eat();



        }

    }

  }

}
