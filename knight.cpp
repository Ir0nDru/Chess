#include "knight.h"

Knight::Knight(QString team):Piece(team)
{
    setup();
}

Knight::~Knight()
{

}

QList<int *> Knight::moves()
{

}

void Knight::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/sprites/knight1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/sprites/knight2.png"));
    }
}
