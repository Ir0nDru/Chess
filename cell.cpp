#include "cell.h"
#include "game.h"
#include <QDebug>

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
        //TODO: add check for which side piece is on
        if (this->piece != NULL){
            if (game->getTurn() == this->piece->getTeam()){
    //        QList<QPair<int, int>> possibleMoves = piece->moves();
    //        qDebug() << "==============================";
    //        for (int i = 0; i < possibleMoves.length(); i++){
    //            qDebug() << i << ":" << possibleMoves[i].first << possibleMoves[i].second;
    //        }
                game->setSelectedFrom(this);
                this->highlight();
                waitingTurn = true;
            }
        }
    }
    else{
        //if same cell then off
        if (game->getSelectedFrom() == this){
            game->setSelectedFrom(NULL);
            this->lightOff();
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
    //this->piece->placeFigure(this->getCoords(), this->getCellSize());
}

void Cell::replaceFigure()
{
    this->piece = NULL;
}

void Cell::removeFigure()
{
    //TODO: add memory clearance
    QList<Piece *> pieces = game->getWhiteTeam() + game->getBlackTeam();
    if (this->piece->getTeam() == "WHITE"){
        game->whiteTeam.removeOne(this->piece);
    }
    else{
        game->blackTeam.removeOne(this->piece);
    }
    delete this->piece;
    this->piece = NULL;
    pieces = game->getWhiteTeam() + game->getBlackTeam();
}

void Cell::highlight()
{
    if(color == "BLACK" || color == "WHITE"){
        //isClicked = true;
        setBrush(pressed);
    }
}

void Cell::lightOff()
{
    //qDebug() << getColor();
    if(getColor() == "WHITE"){
        //isClicked = false;
        setBrush(white);
    }
    else if(getColor() == "BLACK"){
        //isClicked = false;
        setBrush(black);
    }
}

void Cell::move(Cell *cell)
{
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
    //qDebug() << game->whiteKing->check(game->whiteKing->x, game->whiteKing->y);
}

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
    //qDebug() << "==============================";
    for (int i = 0; i < possibleMoves.length() && !possibility; i++){
        //qDebug() << possibleMoves[i].first << possibleMoves[i].second;
        if(this->x == possibleMoves[i].first && this->y == possibleMoves[i].second){
            possibility = true;
        }
    }
    return possibility;
}

