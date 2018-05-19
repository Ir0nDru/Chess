#include "rook.h"

Rook::Rook(QString team):Piece(team)
{
    setup();
}

Rook::~Rook()
{

}

QList<int*> Rook::moves()
{

}

void Rook::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/sprites/rook1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/sprites/rook2.png"));
    }
}
