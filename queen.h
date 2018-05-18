#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen(QString team);
    ~Queen();
    void moves();
private:
    void setup();
};

#endif // QUEEN_H
