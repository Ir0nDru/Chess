#include "cell.h"
#include "game.h"
#include <QDebug>
#include <typeinfo>
#include <iostream>

extern Game * game;
Cell::Cell()
{
    x = 0;
    y = 0;
    piece = NULL;
    isClicked = false;
    setRect(0, 0, cellsize, cellsize);
    //setPen(Qt::black);
    color = "WHITE";
    setBrush(white);
}

Cell::Cell(int posX, int posY, QString cellColor, qreal startSpaceX, qreal startSpaceY)
{
    x = posX;
    y = posY;
    coords.first = x;
    coords.second = y;
    piece = NULL;
    isClicked = false;
    setRect(startSpaceX + cellsize * posX, startSpaceY + cellsize * posY, cellsize, cellsize);
    cellColor = cellColor.toUpper();
    color = cellColor;
    if (color == "WHITE"){
        setBrush(white);
    }
    else{
        color = "BLACK";
        setBrush(black);
    }
}

int *Cell::getCoords()
{
    int temp[] = {x,y};
    return temp;
}

QPair<int, int> Cell::getCoord()
{
    return coords;
}

qreal Cell::getCellSize()
{
    return cellsize;
}

QString Cell::getColor()
{
    return this->color;
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if (!waitingTurn){
        //get cell with piece
        if (this->piece != NULL){
            if (game->getTurn() == this->piece->getTeam()){
                game->setSelectedFrom(this);
                //castling();
                this->setBrush(currentCell);
                QList<QPair<int, int> > moves = this->piece->moves();
                QPair<int,int> coord;
                foreach (coord, moves){
                    for(int i = 0; i < 64; i++){
                        qDebug()<<game->getCell(i)->getCoord();
                        if(coord == game->getCell(i)->getCoord()){
                            toBrush.append(game->getCell(i));
                        }
                    }
                }
                foreach (Cell* cell, toBrush) {
                    if(cell->getPiece()){
                        if(cell->getPiece()->getTeam() != this->getPiece()->getTeam()){
                            cell->setBrush(attacked);
                        }
                    }
                    else{
                        cell->highlight();
                    }
                }
                waitingTurn = true;

            }
        }
    }
    else{
        //if same cell then off
        if (game->getSelectedFrom() == this){
            game->setSelectedFrom(NULL);
            this->lightOff();
            foreach (Cell* cell, toBrush) {
                cell->lightOff();
            }
            waitingTurn = false;
        }
        //else move
        else{
            if (moveIsPossible()){
                move(game->getSelectedFrom());
                game->changeTurn();
                game->checkVictory();
                qDebug() << game->getTurn();
                waitingTurn = false;
            }
        }
    }

}
void Cell::placeFigure(Piece *p)
{
    p->setCoords(x,y);
    p->setPos(cellsize * x + offset, cellsize * y + offset);
    this->piece = p;
}

void Cell::replaceFigure()
{
    this->piece = NULL;
}

void Cell::removeFigure()
{
    if(this->piece){
        if (this->piece->getTeam() == "WHITE"){
            game->whiteTeam.removeOne(this->piece);
        }
        else{
            game->blackTeam.removeOne(this->piece);
        }
        delete this->piece;
        this->piece = NULL;
    }
}

void Cell::highlight()
{
    if(color == "BLACK"){
        //isClicked = true;
        setBrush(possibleMovesAtBlack);
    }
    else{
        setBrush(possibleMovesAtWhite);
    }
}

void Cell::lightOff()
{
    if(getColor() == "WHITE"){
        setBrush(white);
    }
    else if(getColor() == "BLACK"){
        setBrush(black);
    }
}

void Cell::move(Cell *cell)
{
//    if(this->getCoord() == QPair<int, int>(7,7) && this->getPiece()->getTurn() == 0){
//        if(cell->getCoord() == QPair<int, int>(4,7) && cell->getPiece()->getTurn() == 0){
//            if(game->getCell(62)->getPiece() == NULL && game->getCell(61)->getPiece() == NULL){
//                game->getCell(62)->placeFigure(cell->getPiece());
//                game->getCell(61)->placeFigure(this->getPiece());
//                cell->replaceFigure();
//                this->replaceFigure();
//            }
//        }
//    }
    if (this->hasPiece()){
        this->removeFigure();
        this->placeFigure(cell->piece);
        cell->replaceFigure();
        cell->lightOff();
    }
    else{
        this->placeFigure(cell->piece);
        cell->replaceFigure();
        cell->lightOff();
    }
    this->piece->incTurn();
}

//void Cell::castling()
//{
//   if(game->getGoFrom()->getCoord() == QPair<int, int>(4,7))
//       qDebug()<<"kek";
//}

bool Cell::hasPiece()
{
    if (this->piece != NULL){
        return true;
    }
    else{
        return false;
    }
}

bool Cell::moveIsPossible() //check if this cell's coords are in possible movement coords
{
    bool possibility = false;
    QList<QPair<int, int> > possibleMoves = game->getSelectedFrom()->piece->moves();
    for (int i = 0; i < possibleMoves.length() && !possibility; i++){
        if(this->x == possibleMoves[i].first && this->y == possibleMoves[i].second){
            possibility = true;
        }
    }
    return possibility;
}

void Cell::setColor(QColor color)
{
    setBrush(color);
}

Piece *Cell::getPiece()
{
    return piece;
}

