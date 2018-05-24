#include "blackfactory.h"

QList<Piece *> BlackFactory::createTeam()
{
    QList<Piece*> team;

    team.append(createRook());
    team.append(createKnight());
    team.append(createBishop());
    team.append(createQueen());
    team.append(createKing());
    team.append(createBishop());
    team.append(createKnight());
    team.append(createRook());
    team.append(createPawn());
    team.append(createPawn());
    team.append(createPawn());
    team.append(createPawn());
    team.append(createPawn());
    team.append(createPawn());
    team.append(createPawn());
    team.append(createPawn());

    return team;
}

Pawn *BlackFactory::createPawn()
{
    return new Pawn("BLACK");
}

Knight *BlackFactory::createKnight()
{
    return new Knight("BLACK");
}

Bishop *BlackFactory::createBishop()
{
    return new Bishop("BLACK");
}

Rook *BlackFactory::createRook()
{
    return new Rook("BLACK");
}

Queen *BlackFactory::createQueen()
{
    return new Queen("BLACK");
}

King *BlackFactory::createKing()
{
    return new King("BLACK");
}
