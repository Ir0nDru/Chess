#ifndef PAWN_H
#define PAWN_H

#include <piece.h>

class Pawn: public Piece
{
public:
    Pawn();
    ~Pawn();
private:
    void setup(QString team = "BLACK");
};

#endif // PAWN_H
