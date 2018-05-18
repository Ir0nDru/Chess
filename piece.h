#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>

class Piece: public QGraphicsPixmapItem
{
public:
    Piece * giveIt();
    Piece(QString team);
    QString getTeam();
    //void placeFigure(int * coords, qreal cellsize);
    virtual void moves() = 0;
private:
    virtual void setup() = 0;
protected:
    QString team;
};

#endif // PIECE_H
