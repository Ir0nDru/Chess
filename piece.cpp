#include "piece.h"


void Piece::setup()
{

}

void Piece::placeFigure(int * coords, qreal cellsize)
{
    setX(cellsize * coords[0] + offset);
    setY(cellsize * coords[1] + offset);
}


void Piece::move()
{

}

Piece *Piece::giveIt()
{
    return this;
}
