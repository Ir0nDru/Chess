#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen(QString team);
    ~Queen();
    QList<QPair<int, int> > moves();
private:
    void setup();
};

#endif // QUEEN_H
