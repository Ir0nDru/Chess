#ifndef PAWN_H
#define PAWN_H

#include <piece.h>

class Pawn: public Piece
{
public:
    Pawn(QString team);
    ~Pawn();
    QList<int *> moves();
private:
    void setup();
};

#endif // PAWN_H
