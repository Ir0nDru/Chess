#include "gameover.h"
#include "ui_gameover.h"

//Game * game;

Gameover::Gameover(QString winner, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gameover)
{
    ui->setupUi(this);
    ui->label->setText(winner + "Wins");
}

Gameover::~Gameover()
{
    delete ui;
}

void Gameover::on_closeButton_clicked()
{
    this->close();
}

//void Gameover::on_playButton_clicked()
//{
//    game = new Game();
//    game->show();
//    delete this;
//}
