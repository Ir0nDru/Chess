#include "king.h"

King::King(QString team):Piece(team)
{
    setup();
}

King::~King()
{

}

QList<int *> King::moves()
{

}

void King::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/sprites/king1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/sprites/king2.png"));
    }
}
