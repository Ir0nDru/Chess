#ifndef KNIGHT_H
#define KNIGHT_H

#include <piece.h>

class Knight : public Piece
{
public:
    Knight(QString team);
    ~Knight();
    QList<int*> moves();
private:
    void setup();
};

#endif // KNIGHT_H
