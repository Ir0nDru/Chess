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
        setPixmap(QPixmap(":/img/rook1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/rook2.png"));
    }
}
