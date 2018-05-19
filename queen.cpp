#include "queen.h"

Queen::Queen(QString team):Piece(team)
{
    setup();
}

Queen::~Queen()
{

}

QList<QPair<int, int> > Queen::moves()
{
    QList<QPair<int, int>> coords;
    return coords;
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
