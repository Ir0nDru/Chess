#include "whitefactory.h"



QList<Piece *> WhiteFactory::createTeam()
{
    QList<Piece*> team;

    team.append(createPawn());
    team.append(createPawn());
    team.append(createPawn());
    team.append(createPawn());
    team.append(createPawn());
    team.append(createPawn());
    team.append(createPawn());
    team.append(createPawn());
    team.append(createRook());
    team.append(createKnight());
    team.append(createBishop());
    team.append(createKing());
    team.append(createQueen());
    team.append(createBishop());
    team.append(createKnight());
    team.append(createRook());


    return team;
}

Pawn *WhiteFactory::createPawn()
{
    return new Pawn("WHITE");
}

Knight *WhiteFactory::createKnight()
{
    return new Knight("WHITE");
}

Bishop *WhiteFactory::createBishop()
{
    return new Bishop("WHITE");
}

Rook *WhiteFactory::createRook()
{
    return new Rook("WHITE");
}

Queen *WhiteFactory::createQueen()
{
    return new Queen("WHITE");
}

King *WhiteFactory::createKing()
{
    return new King("WHITE");
}

