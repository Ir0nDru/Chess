#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <cell.h>
#include <piece.h>
#include <pawn.h>
#include <knight.h>

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    void addToScene(QGraphicsItem * item);
    void removeFromScene(QGraphicsItem * item);
private:
    QGraphicsScene * scene;
    QList <Cell *> cells;
};

#endif // GAME_H
