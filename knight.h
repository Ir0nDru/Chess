#ifndef KNIGHT_H
#define KNIGHT_H

#include <piece.h>

class Knight : public Piece
{
public:
    Knight(QString team);
    ~Knight();
    QList<QPair<int, int> > moves();
private:
    void setup();
    bool freeToMove(int x, int y, QList<Piece*> pieces);
};

#endif // KNIGHT_H
