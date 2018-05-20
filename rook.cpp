#include "rook.h"
#include "game.h"

extern Game * game;

Rook::Rook(QString team):Piece(team)
{
    setup();
}

Rook::~Rook()
{

}

QList<QPair<int, int> > Rook::moves()
{
    QList<Piece*> pieces = game->getBlackTeam() + game->getWhiteTeam();
    QList<QPair<int, int>> coords;
    bool isClear = true;
    for(int i = x+1; i <= 7 && isClear; i++){
        foreach(Piece* p, pieces){
            if(i == p->x && y == p->y){
                isClear = false;
                if (!isClear && (p->getTeam() != this->getTeam())){
                    coords.append(QPair<int,int>(i,y));
                }
            }
        }
        if(isClear){
            coords.append(QPair<int,int>(i,y));
        }
    }
    isClear = true;
    for(int i = x-1; i >= 0 && isClear; i--){
        foreach(Piece* p, pieces){
            if(i == p->x && y == p->y){
                isClear = false;
                if (!isClear && (p->getTeam() != this->getTeam())){
                    coords.append(QPair<int,int>(i,y));
                }
            }
        }
        if(isClear){
            coords.append(QPair<int,int>(i,y));
        }
    }
    isClear = true;
    for(int i = y-1; i >= 0 && isClear; i--){
        foreach(Piece* p, pieces){
            if(i == p->y && x == p->x){
                isClear = false;
                if (!isClear && (p->getTeam() != this->getTeam())){
                    coords.append(QPair<int,int>(x,i));
                }
            }
        }
        if(isClear){
            coords.append(QPair<int,int>(x, i));
        }
    }
    isClear = true;
    for(int i = y+1; i <= 7 && isClear; i++){
        foreach(Piece* p, pieces){
            if(i == p->y && x == p->x){
                isClear = false;
                if (!isClear && (p->getTeam() != this->getTeam())){
                    coords.append(QPair<int,int>(x, i));
                }
            }
        }
        if(isClear){
            coords.append(QPair<int,int>(x, i));
        }
    }
    return coords;
}

void Rook::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/sprites/rook1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/sprites/rook2.png"));
    }
}
