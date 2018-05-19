#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
public:
    King(QString team);
    ~King();
    QList<QPair<int, int>> moves();
private:
    void setup();
};

#endif // KING_H
