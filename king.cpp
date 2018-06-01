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


//    if (this->getTurn() == 0 && game->getCell(63)->getPiece()->getTurn() == 0){
//        if(freeToMove(5, 7, pieces) && freeToMove(5, 7, pieces)){
//            coords.append(QPair<int, int>(6,7));
//        }
//    }

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
//    if (this->getTeam() == "WHITE"){
//        if (this->getTurn() == 0 && game->getCell(63)->getPiece()->getTurn() == 0){
//            bool isEmptyBetwen = true;
//            for (int i = 60; i <= 62 && isEmptyBetwen; i++){
//                if(game->getCell(i)->getPiece() != NULL){
//                    isEmptyBetwen = false;
//                }
//        }
//            if(isEmptyBetwen){
//                coords.append(QPair<int, int>(7,7));
//            }

//        if (game->getCell(56)->getPiece()->getTurn() == 0){
//             coords.append(QPair<int, int>(0,7));
//        }
//    }
//    if (this->getTeam() == "BLACK"){
//        if (game->getCell(7)->getPiece()->getTurn() == 0){
//             coords.append(QPair<int, int>(7,0));
//        }

//        if (game->getCell(0)->getPiece()->getTurn() == 0){
//             coords.append(QPair<int, int>(0,0));
//        }
//    }
//  }
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
