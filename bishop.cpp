#include "bishop.h"

Bishop::Bishop(QString team):Piece(team)
{
    setup();
}

Bishop::~Bishop()
{

}

QList<int *> Bishop::moves()
{

}

void Bishop::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/sprites/bishop1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/sprites/bishop2.png"));
    }
}
