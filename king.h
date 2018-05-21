#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
public:
    King(QString team);
    ~King();
    QList<QPair<int, int>> moves();
    bool check();
private:
    void setup();
    bool freeToMove(int x, int y, QList<Piece *> pieces);
};

#endif // KING_H
