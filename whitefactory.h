#ifndef WHITEFACTORY_H
#define WHITEFACTORY_H

#include "factory.h"

class WhiteFactory : public Factory
{
public:
    QList<Piece*> createTeam() override;
private:
    Pawn* createPawn();
    Knight* createKnight();
    Bishop* createBishop();
    Rook* createRook();
    Queen* createQueen();
    King* createKing();
};

#endif // WHITEFACTORY_H
