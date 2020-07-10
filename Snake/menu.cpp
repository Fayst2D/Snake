#include "menu.h"

Menu::Menu() : QWidget()
{ 
    Play = new QPushButton("PLAY");
    Quit = new QPushButton("QUIT");



    words_size.setPixelSize(220);
    Quit->setFont(words_size);
    Play->setFont(words_size);


    connect(Play,SIGNAL(clicked()),this,SLOT(play_clicked()));
    connect(Quit,SIGNAL(clicked()),this,SLOT(quit_clicked()));


    lay.addWidget(Play);
    lay.addWidget(Quit);

    setLayout(&lay);

    this->move(800,200);





}

void Menu::play_clicked()
{


    p.showFullScreen();
    close();

}

void Menu::quit_clicked()
{

    close();

}


