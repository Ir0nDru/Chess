#include "knight.h"

Knight::Knight(QString team):Piece(team)
{
    setup();
}

Knight::~Knight()
{

}

QList<QPair<int, int> > Knight::moves()
{
    QList<QPair<int, int>> coords;
    return coords;
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
