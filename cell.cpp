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
            game->setSelectedFrom(this);
            this->highlight();
            waitingTurn = true;
        }
    }
    else{
        //if same cell then off
        if (game->getSelectedFrom() == this){
            game->setSelectedFrom(NULL);
            this->lightOff();
        }
        //else move
        //TODO: check path variants and possible ally units to step on
        else{
            move(game->getSelectedFrom());
            //this->lightOff();
        }
        waitingTurn = false;
    }


//    if (this->piece != NULL && !waitingTurn){
//        waitingTurn = true;
//        //Color cell
//        //qDebug() << brush().color().rgb();
//        if(color == "WHITE" && isClicked == true){
//            isClicked = false;
//            setBrush(white);
//        }
//        else if(color == "BLACK" && isClicked == true){
//            isClicked = false;
//            setBrush(black);
//        }
//        else if((color == "BLACK" || color == "WHITE") && isClicked == false){
//            isClicked = true;
//            setBrush(pressed);
//        }
//    }
//    else if(waitingTurn){
//        waitingTurn = false;
//        if((color == "BLACK" || color == "WHITE") && isClicked == false){
//                    isClicked = true;
//                    setBrush(pressed);
//                }
//    }
    qDebug() << waitingTurn;
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
    delete this->piece;
    this->piece = NULL;
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
    qDebug() << getColor();
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


//int Cell::waitingTurn = false;
