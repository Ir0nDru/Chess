#include "knight.h"
#include "game.h"

extern Game* game;

Knight::Knight(QString team):Piece(team)
{
    setup();
}

Knight::~Knight()
{

}

QList<QPair<int, int> > Knight::moves()
{
    QList<Piece*> pieces;
    QList<QPair<int, int>> coords;

    if (this->getTeam() == "WHITE"){
        pieces = game->getWhiteTeam();
    }
    else{
        pieces = game->getBlackTeam();
    }


    if (freeToMove(this->x+1, this->y-2, pieces)){
        coords.append(QPair<int, int>(this->x+1, this->y-2));
    }
    if (freeToMove(this->x+2, this->y-1, pieces)){
        coords.append(QPair<int, int>(this->x+2, this->y-1));
    }
    if (freeToMove(this->x+2, this->y+1, pieces)){
        coords.append(QPair<int, int>(this->x+2, this->y+1));
    }
    if (freeToMove(this->x+1, this->y+2, pieces)){
        coords.append(QPair<int, int>(this->x+1, this->y+2));
    }
    if (freeToMove(this->x-1, this->y+2, pieces)){
        coords.append(QPair<int, int>(this->x-1, this->y+2));
    }
    if (freeToMove(this->x-2, this->y+1, pieces)){
        coords.append(QPair<int, int>(this->x-2, this->y+1));
    }
    if (freeToMove(this->x-2, this->y-1, pieces)){
        coords.append(QPair<int, int>(this->x-2, this->y-1));
    }
    if (freeToMove(this->x-1, this->y-2, pieces)){
        coords.append(QPair<int, int>(this->x-1, this->y-2));
    }

    return coords;
}

void Knight::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/sprites/knight1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/sprites/knight2.png"));
    }
}

bool Knight::freeToMove(int x, int y, QList<Piece *> pieces)
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
