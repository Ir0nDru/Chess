#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>

class Bishop : public Piece
{
public:
    Bishop(QString team);
    ~Bishop();
    QList<int*> moves();
private:
    void setup();
};

#endif // BISHOP_H
