#include "pawn.h"

Pawn::Pawn()
{
    setup();
}

Pawn::~Pawn()
{
    delete this;
}

void Pawn::setup(QString team)
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/pawn1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/pawn2.png"));
    }
}
