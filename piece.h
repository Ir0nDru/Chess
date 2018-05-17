#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>
#include <cell.h>

class Piece: public QGraphicsPixmapItem
{
public:
    Piece * giveIt();
    void setup();
    void placeFigure(const Cell &cell);
    virtual void move() = 0;
private:
    qreal offset = 20;
};

#endif // PIECE_H
