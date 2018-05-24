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
#include <gameover.h>
#include <QDebug>

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    void addToScene(QGraphicsItem * item);
    void removeFromScene(QGraphicsItem * item);
    void setSelectedFrom(Cell * cell); //there are setter and getter for cells that we are going to press
    Cell * getSelectedFrom();
    QList<Piece*> getWhiteTeam();
    QList<Piece*> getBlackTeam();
    //Little feature or hack that ruines all architecture but program doesn't crush anymore (KLUDGE)
    QList <Piece*> whiteTeam;
    QList <Piece*> blackTeam;
    QString getTurn();
    void checkVictory();
    void changeTurn();
private:
    QGraphicsScene * scene;
    QList <Cell *>  cells;
    Cell * goFrom;
    QString turn;
    QGraphicsTextItem  * turnTable;
    void gameover();
};

#endif // GAME_H
