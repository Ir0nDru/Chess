#include "rook.h"

Rook::Rook(QString team):Piece(team)
{
    setup();
}

Rook::~Rook()
{

}

QList<QPair<int, int> > Rook::moves()
{
    QList<QPair<int, int>> coords;
    return coords;
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
