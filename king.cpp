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
        setPixmap(QPixmap(":/img/king1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/king2.png"));
    }
}
