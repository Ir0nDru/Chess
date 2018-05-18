#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <cell.h>
#include <piece.h>
#include <pawn.h>
#include <knight.h>
#include <bishop.h>
#include <king.h>
#include <queen.h>
#include <rook.h>

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    void addToScene(QGraphicsItem * item);
    void removeFromScene(QGraphicsItem * item);
    void setSelectedFrom(Cell * cell); //there are setters and getters for cells that we are going to press
    void setSelectedTo(Cell * cell);
    Cell * getSelectedFrom();
    Cell * getSelectedTo();
private:
    QGraphicsScene * scene;
    QList <Cell *> cells;
    Cell * goFrom;
    Cell * goTo;
};

#endif // GAME_H
