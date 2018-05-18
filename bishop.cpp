#include "bishop.h"

Bishop::Bishop(QString team):Piece(team)
{
    setup();
}

Bishop::~Bishop()
{

}

void Bishop::moves()
{

}

void Bishop::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/bishop1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/bishop2.png"));
    }
}
