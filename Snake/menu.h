#ifndef MENU_H
#define MENU_H

#include "snake.h"


class Menu : public QWidget
{
    Q_OBJECT

public:

    Menu();

private:
    QPushButton *Play;
    QPushButton *Quit;
    QVBoxLayout lay;
    QFont words_size;
    Snake p;

private slots:

    void play_clicked();
    void quit_clicked();




};

#endif // MENU_H
