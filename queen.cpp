#include "queen.h"

Queen::Queen(QString team):Piece(team)
{
    setup();
}

Queen::~Queen()
{

}

void Queen::moves()
{

}

void Queen::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/queen1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/queen2.png"));
    }
}
