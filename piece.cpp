#include "piece.h"

Piece::Piece(QString team)
{
    this->team = team.toUpper();
}

QString Piece::getTeam()
{
    return team.toUpper();
}

//void Piece::setup()
//{

//}

//void Piece::placeFigure(int * coords, qreal cellsize)
//{
  //  setPos(cellsize * coords[0] + offset, cellsize * coords[1] + offset);
//    setX(cellsize * coords[0] + offset);
//    setY(cellsize * coords[1] + offset);
//}


//void Piece::move()
//{

//}

Piece *Piece::giveIt()
{
    return this;
}

//Piece::Piece()
//{

//}

