#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <piece.h>

class Cell: public QGraphicsRectItem
{
public:
    Cell();
    Cell(int posX, int posY, QString cellColor="", qreal startSpaceX = 50, qreal startSpaceY = 50);
    int * getCoords();
    qreal getCellSize();
    QString getColor();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void placeFigure(Piece * p);
    void removeFigure();
    void highlight();
    void lightOff();
    void move(Cell * cell);
    bool hasPiece();
private:
    int x;
    int y;
    qreal cellsize = 100;
    qreal offset = 70;
    QString color;
    QColor white = QColor::fromRgb(240,200,200);
    QColor black = QColor::fromRgb(80,20,20);
    QColor pressed = QColor::fromRgb(245,20,20);
    bool isClicked;
    Piece * piece;
    static bool waitingTurn; //global variable shows whether any cell is selected at the moment
};

#endif // CELL_H
