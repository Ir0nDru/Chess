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
    QPair<int, int> getCoord();
    qreal getCellSize();
    QString getColor();
    QList<Cell*> toBrush;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void placeFigure(Piece * p);
    void replaceFigure();
    void removeFigure();
    void highlight();
    void lightOff();
    void move(Cell * cell);
   // void castling();
    bool hasPiece();
    bool moveIsPossible();
    void setColor(QColor color);
    Piece* getPiece();
private:
    QPair<int, int> coords;
    int x;
    int y;
    qreal cellsize = 80;
    qreal offset = 60;
    QString color;
    QColor white = QColor::fromRgb(240,200,200);
    QColor black = QColor::fromRgb(80,20,20);
    QColor possibleMovesAtWhite = QColor::fromRgb(125,245,135);
    QColor possibleMovesAtBlack = QColor::fromRgb(98,188,105);
    QColor currentCell = QColor::fromRgb(0,245,63);
    QColor attacked = QColor::fromRgb(245,20,20);
    bool isClicked;
    Piece * piece;
    static bool waitingTurn; //global variable shows whether any cell is selected at the moment
};

#endif // CELL_H
