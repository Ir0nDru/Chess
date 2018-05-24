#include "king.h"
#include "game.h"

extern Game * game;

King::King(QString team):Piece(team)
{
    setup();
}

King::~King()
{

}

QList<QPair<int, int> > King::moves()
{
    QList<Piece*> pieces;
    QList<QPair<int, int> > coords;

    if (this->getTeam() == "WHITE"){
        pieces = game->getWhiteTeam();
    }
    else{
        pieces = game->getBlackTeam();
    }


    if (freeToMove(this->x, this->y-1, pieces)){
        coords.append(QPair<int, int>(this->x, this->y-1));
    }
    if (freeToMove(this->x+1, this->y-1, pieces)){
        coords.append(QPair<int, int>(this->x+1, this->y-1));
    }
    if (freeToMove(this->x+1, this->y, pieces)){
        coords.append(QPair<int, int>(this->x+1, this->y));
    }
    if (freeToMove(this->x+1, this->y+1, pieces)){
        coords.append(QPair<int, int>(this->x+1, this->y+1));
    }
    if (freeToMove(this->x, this->y+1, pieces)){
        coords.append(QPair<int, int>(this->x, this->y+1));
    }
    if (freeToMove(this->x-1, this->y+1, pieces)){
        coords.append(QPair<int, int>(this->x-1, this->y+1));
    }
    if (freeToMove(this->x-1, this->y, pieces)){
        coords.append(QPair<int, int>(this->x-1, this->y));
    }
    if (freeToMove(this->x-1, this->y-1, pieces)){
        coords.append(QPair<int, int>(this->x-1, this->y-1));
    }

    return coords;
}

int King::type() const
{
    return Type;
}

bool King::check(int X, int Y)
{
    bool check = false;
    QList<Piece *> pieces;

    if (this->getTeam() == "WHITE"){
        pieces = game->getBlackTeam();
    }
    else{
        pieces = game->getWhiteTeam();
    }

    foreach(Piece * piece, pieces){
        QList<QPair<int, int> > enemyMoves = piece->moves();
        for (int i = 0; i < enemyMoves.length(); i++){
            if (X == enemyMoves[i].first && Y == enemyMoves[i].second){
                check = true;
            }
        }
    }

    return check;
}

void King::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/sprites/king1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/sprites/king2.png"));
    }
}


bool King::freeToMove(int x, int y, QList<Piece *> pieces)
{
    bool isClear = true;
    if (x <= 7 && x >= 0 && y <= 7 && y >= 0){
        foreach(Piece * p, pieces){
            if(p->x == x && p->y == y){
                isClear = false;
            }
        }
    }
    else{
        isClear = false;
    }
    return isClear;
}
