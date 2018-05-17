#include "game.h"
#include <QDesktopWidget>
#include <iostream>


Game::Game()
{
    setFocusPolicy(Qt::StrongFocus);
    setFixedSize(900, 900);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 900, 900);
    //Draw field
    QGraphicsRectItem * borderOuter = new QGraphicsRectItem();
    QGraphicsRectItem * borderInner = new QGraphicsRectItem();

    borderOuter->setRect(0,0,900,900);
    borderOuter->setBrush(QBrush(QColor::fromRgb(55, 20, 10)));
    borderInner->setRect(50,50,800,800);
    borderInner->setPen(QPen(QColor::fromRgb(85, 50, 40)));
    borderInner->setBrush(QBrush(QColor::fromRgb(85, 50, 40)));

    addToScene(borderOuter);
    addToScene(borderInner);
    //Draw axis
    QGraphicsTextItem * letters[8];
    QString letter = QString("ABCDEFGH");
    for (int i=0; i<8; i++){
        letters[i] = new QGraphicsTextItem();
        letters[i]->setFont(QFont("times", 20));
        letters[i]->setDefaultTextColor(QColor::fromRgb(180, 170, 0));
        letters[i]->setPlainText(QString(letter[i]));
        letters[i]->setPos(85 + 100*i, 855);
        addToScene(letters[i]);
    }

    QGraphicsTextItem * nums[8];
    for (int i=0; i<8; i++){
        nums[i] = new QGraphicsTextItem();
        nums[i]->setFont(QFont("times", 20));
        nums[i]->setDefaultTextColor(QColor::fromRgb(180, 170, 0));
        nums[i]->setPlainText(QString::number(8 - i));
        nums[i]->setPos(15, 80 + 100*i);
        addToScene(nums[i]);
    }



    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //adding cells
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            Cell * cell;
            if ((i + j) % 2 == 0){
                cell = new Cell(j,i,"WHITE");
            }
            else{
                cell = new Cell(j,i,"BLACK");
            }
            cells.append(cell);
            addToScene(cell);
        }
    }
    //adding piece
    Pawn * p = new Pawn("BLACK");
    Pawn * p1 = new Pawn("WHITE");
    Knight * k1 = new Knight("BLACK");
    Knight * k2 = new Knight("WHITE");
    cells[0]->placeFigure(p);
    cells[27]->placeFigure(p1);
    cells[39]->placeFigure(k1);
    cells[58]->placeFigure(k2);
    addToScene(p);
    addToScene(p1);
    addToScene(k1);
    addToScene(k2);

}

void Game::addToScene(QGraphicsItem *item)
{
    scene->addItem(item);
}

void Game::removeFromScene(QGraphicsItem *item)
{
    scene->removeItem(item);
}
