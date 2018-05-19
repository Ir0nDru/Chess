#include "king.h"

King::King(QString team):Piece(team)
{
    setup();
}

King::~King()
{

}

QList<QPair<int, int> > King::moves()
{
    QList<QPair<int, int>> coords;
    return coords;
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
