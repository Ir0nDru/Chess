#include "bishop.h"
#include "game.h"

extern Game * game;

Bishop::Bishop(QString team):Piece(team)
{
    setup();
}

Bishop::~Bishop()
{

}

QList<QPair<int, int> > Bishop::moves()
{
    QList<Piece*> pieces = game->getBlackTeam() + game->getWhiteTeam();
    QList<QPair<int, int>> coords;
    bool isClear = true;
    for(int i = x+1; i <= 7 && y-1-(i-(x+1)) >= 0 && isClear; i++){
        foreach(Piece* p, pieces){
            if(i == p->x && y-1-(i-(x+1)) == p->y){
                isClear = false;
                if (!isClear && (p->getTeam() != this->getTeam())){
                    coords.append(QPair<int,int>(i,y-1-(i-(x+1))));
                }
            }
        }
        if(isClear){
            coords.append(QPair<int,int>(i,y-1-(i-(x+1))));
        }
    }
    isClear = true;
    for(int i = x+1; i <= 7 && y+1+(i-(x+1)) <= 7 && isClear; i++){
        foreach(Piece* p, pieces){
            if(i == p->x && y+1+(i-(x+1)) == p->y){
                isClear = false;
                if (!isClear && (p->getTeam() != this->getTeam())){
                    coords.append(QPair<int,int>(i,y+1+(i-(x+1))));
                }
            }
        }
        if(isClear){
            coords.append(QPair<int,int>(i,y+1+(i-(x+1))));
        }
    }
    isClear = true;
    for(int i = x-1; i >= 0 && y+1+(x-1-i) <= 7 && isClear; i--){
        foreach(Piece* p, pieces){
            if(i == p->x && y+1+(x-1-i) == p->y){
                isClear = false;
                if (!isClear && (p->getTeam() != this->getTeam())){
                    coords.append(QPair<int,int>(i,y+1+(x-1-i)));
                }
            }
        }
        if(isClear){
            coords.append(QPair<int,int>(i,y+1+(x-1-i)));
        }
    }
    isClear = true;
    for(int i = x-1; i >= 0 && y-1-(x-1-i) >= 0 && isClear; i--){
        foreach(Piece* p, pieces){
            if(i == p->x && y-1-(x-1-i) == p->y){
                isClear = false;
                if (!isClear && (p->getTeam() != this->getTeam())){
                    coords.append(QPair<int,int>(i,y-1-(x-1-i)));
                }
            }
        }
        if(isClear){
            coords.append(QPair<int,int>(i,y-1-(x-1-i)));
        }
    }

    return coords;
}

void Bishop::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/sprites/bishop1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/sprites/bishop2.png"));
    }
}
