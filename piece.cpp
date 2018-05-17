#include "piece.h"


void Piece::setup()
{

}

void Piece::placeFigure(const Cell &cell)
{
    const int coords[2] = cell.getCoords();
    qreal cellsize = cell.getCellSize();
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
