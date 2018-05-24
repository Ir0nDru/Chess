#ifndef BLACKFACTORY_H
#define BLACKFACTORY_H

#include "factory.h"

class BlackFactory : public Factory
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

#endif // BLACKFACTORY_H
