#include "knight.h"

Knight::Knight(QString team):Piece(team)
{
    setup();
}

Knight::~Knight()
{

}

void Knight::moves()
{

}

void Knight::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/knight1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/knight2.png"));
    }
}
