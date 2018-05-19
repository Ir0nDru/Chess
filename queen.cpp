#include "queen.h"

Queen::Queen(QString team):Piece(team)
{
    setup();
}

Queen::~Queen()
{

}

QList<int *> Queen::moves()
{

}

void Queen::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/sprites/queen1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/sprites/queen2.png"));
    }
}
