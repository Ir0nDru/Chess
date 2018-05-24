#include "queen.h"
#include "game.h"

extern Game * game;

Queen::Queen(QString team):Piece(team)
{
    setup();
}

Queen::~Queen()
{

}

QList<QPair<int, int> > Queen::moves()
{
    QList<Piece*> pieces = game->getBlackTeam() + game->getWhiteTeam();
    QList<QPair<int, int> > coords;
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
    isClear = true;
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

void Queen::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/sprites/queen1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/sprites/queen2.png"));
    }
}
