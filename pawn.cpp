#include "pawn.h"

Pawn::Pawn(QString team):Piece(team)
{
    setup();
}

Pawn::~Pawn()
{

}

void Pawn::moves()
{

}

void Pawn::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/pawn1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/pawn2.png"));
    }
}
