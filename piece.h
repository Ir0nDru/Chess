#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>

class Piece: public QGraphicsPixmapItem
{
public:
    Piece * giveIt();
    Piece(QString team);
    QString getTeam();
    virtual QList<QPair<int, int> > moves() = 0;
    void setCoords(int x,int y);
    void incTurn();
    int x;
    int y;
private:
    virtual void setup() = 0;
protected:
    int turn;
    QString team;
};

#endif // PIECE_H
