#include "piece.h"

Piece::Piece(QString team)
{
    this->team = team.toUpper();
    this->turn = 0;
}

QString Piece::getTeam()
{
    return team.toUpper();
}

void Piece::setCoords(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Piece::incTurn()
{
    this->turn++;
}


Piece *Piece::giveIt()
{
    return this;
}


