#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
public:
    enum { Type = UserType + 1 };
    King(QString team);
    ~King();
    QList<QPair<int, int> > moves();
    virtual int type() const;
    bool check(int X, int Y);
private:
    void setup();
    bool freeToMove(int x, int y, QList<Piece *> pieces);
};

#endif // KING_H
