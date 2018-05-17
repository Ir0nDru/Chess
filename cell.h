#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>

class Cell: public QGraphicsRectItem
{
public:
    Cell();
    Cell(int posX, int posY, QString cellColor="", qreal startSpaceX = 50, qreal startSpaceY = 50);
    int * getCoords();
    qreal getCellSize();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    int x;
    int y;
    qreal cellsize = 100;
    QString color;
    QColor white = QColor::fromRgb(240,200,200);
    QColor black = QColor::fromRgb(80,20,20);
    QColor pressed = QColor::fromRgb(245,20,20);
    bool isClicked;
};

#endif // CELL_H
