#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>

class Bishop : public Piece
{
public:
    Bishop(QString team);
    ~Bishop();
    void moves();
private:
    void setup();
};

#endif // BISHOP_H
