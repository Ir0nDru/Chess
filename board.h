#ifndef BOARD_H
#define BOARD_H

#include  <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>

class Board:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Board();
};

#endif // BOARD_H
