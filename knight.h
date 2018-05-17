#ifndef KNIGHT_H
#define KNIGHT_H

#include <piece.h>

class Knight : public Piece
{
public:
    Knight(QString team);
    ~Knight();
    void moves();
private:
    void setup();
};

#endif // KNIGHT_H
