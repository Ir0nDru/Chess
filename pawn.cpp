#include "pawn.h"
#include "game.h"

extern Game* game;

Pawn::Pawn(QString team):Piece(team)
{
    setup();
}

Pawn::~Pawn()
{

}

QList<QPair<int, int> > Pawn::moves()
{
    QList<Piece*> whiteTeam = game->getWhiteTeam();
    QList<Piece*> blackTeam = game->getBlackTeam();
    QList<QPair<int, int> > coords;
    int k;
    if(turn == 0){
        k = 2;
    }
    else{
        k = 1;
    }
    bool isClear = true;
    if(team == "WHITE"){
        for(int i = y-1; i >= y-k && i>=0 && isClear; i--){
            foreach(Piece* p, whiteTeam){
                if(i == p->y && x == p->x){
                    isClear = false;
                }
            }
            foreach(Piece* p, blackTeam){
                if(i == p->y && x == p->x){
                    isClear = false;
                }
            }
            if(isClear){
                QPair<int,int> temp;
                temp.first = x;
                temp.second = i;
                coords.append(temp);
            }
        }
        foreach(Piece* p, blackTeam){
            if(y-1 == p->y && x-1 == p->x){
                //int temp[] = {p->x,p->y};
                QPair<int,int> temp;
                temp.first = p->x;
                temp.second = p->y;
                coords.append(temp);
            }
            if(y-1 == p->y && x+1 == p->x){
                //int temp[] = {p->x,p->y};
                QPair<int,int> temp;
                temp.first = p->x;
                temp.second = p->y;
                coords.append(temp);
            }
        }
    }
    else{
        for(int i = y+1; i <= y+k && i <= 7 && isClear; i++){
            foreach(Piece* p, whiteTeam){
                if(i == p->y && x == p->x){
                    isClear = false;
                }
            }
            foreach(Piece* p, blackTeam){
                if(i == p->y && x == p->x){
                    isClear = false;
                }
            }
            if(isClear){
                //int temp[] = {x,i};
                QPair<int,int> temp;
                temp.first = x;
                temp.second = i;
                coords.append(temp);
            }
        }
        foreach(Piece* p, whiteTeam){
            if(y+1 == p->y && x-1 == p->x){
                //int temp[] = {p->x,p->y};
                QPair<int,int> temp;
                temp.first = p->x;
                temp.second = p->y;
                coords.append(temp);
            }
            if(y+1 == p->y && x+1 == p->x){
                //int temp[] = {p->x,p->y};
                QPair<int,int> temp;
                temp.first = p->x;
                temp.second = p->y;
                coords.append(temp);
            }
        }
    }
    return coords;
}

void Pawn::setup()
{
    if (team == "BLACK"){
        setPixmap(QPixmap(":/img/sprites/pawn1.png"));
    }
    else{
        setPixmap(QPixmap(":/img/sprites/pawn2.png"));
    }
}
