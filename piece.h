#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>

class Piece: public QGraphicsPixmapItem
{
public:
    Piece * giveIt();
    void setup();
    void placeFigure(int * coords, qreal cellsize);
    virtual void move() = 0;
private:
    qreal offset = 20;
};

#endif // PIECE_H
