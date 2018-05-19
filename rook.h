#ifndef ROOK_H
#define ROOK_H

#include <piece.h>

class Rook : public Piece
{
public:
    Rook(QString team);
    ~Rook();
    QList<QPair<int, int>> moves();
private:
    void setup();
};

#endif // ROOK_H
