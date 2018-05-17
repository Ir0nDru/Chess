#include "cell.h"
#include <QDebug>

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

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << brush().color().rgb();
    if(color == "WHITE" && isClicked == true){
        isClicked = false;
        setBrush(white);
    }
    else if(color == "BLACK" && isClicked == true){
        isClicked = false;
        setBrush(black);
    }
    else if((color == "BLACK" || color == "WHITE") && isClicked == false){
        isClicked = true;
        setBrush(pressed);
    }
}

void Cell::moveHere(Piece *p)
{
    this->piece = p;
    this->piece->placeFigure(this->getCoords(), this->getCellSize());
}
