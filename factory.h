#ifndef FACTORY_H
#define FACTORY_H

#include "piece.h"

#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "king.h"

class Factory
{
public:
    virtual QList<Piece*> createTeam() = 0;
    virtual ~Factory(){}
private:
    virtual Pawn* createPawn() = 0;
    virtual Knight* createKnight() = 0;
    virtual Bishop* createBishop() = 0;
    virtual Rook* createRook() = 0;
    virtual Queen* createQueen() = 0;
    virtual King* createKing() = 0;
};

#endif // FACTORY_H
