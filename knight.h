#ifndef KNIGHT_H
#define KNIGHT_H

#include <piece.h>

class Knight : public Piece
{
public:
    Knight(QString team);
    ~Knight();
    QList<QPair<int, int>> moves();
private:
    void setup();
};

#endif // KNIGHT_H
