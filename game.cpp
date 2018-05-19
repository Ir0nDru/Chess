#include "game.h"
#include <QDesktopWidget>
#include <iostream>

bool Cell::waitingTurn = false;

Game::Game()
{
    goFrom = NULL;
    goTo = NULL;

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
    Pawn * pawn = new Pawn("WHITE");
    Bishop * bishop = new Bishop("BLACK");
    Bishop * b1 = new Bishop("WHITE");
    King * king = new King("WHITE");
    Queen * queen = new Queen("BLACK");
    Knight * knight = new Knight("BLACK");
    Rook * rook = new Rook("WHITE");
    cells[26]->placeFigure(pawn);
    cells[1]->placeFigure(bishop);
    cells[2]->placeFigure(b1);
    cells[39]->placeFigure(king);
    cells[19]->placeFigure(queen);
    cells[17]->placeFigure(knight);
    cells[60]->placeFigure(rook);


    blackTeam.append(bishop);
    blackTeam.append(queen);
    blackTeam.append(knight);

    whiteTeam.append(pawn);
    whiteTeam.append(king);
    whiteTeam.append(rook);
    whiteTeam.append(b1);


    addToScene(pawn);
    addToScene(bishop);
    addToScene(king);
    addToScene(queen);
    addToScene(knight);
    addToScene(rook);
    addToScene(b1);

}

void Game::addToScene(QGraphicsItem *item)
{
    scene->addItem(item);
}

void Game::removeFromScene(QGraphicsItem *item)
{
    scene->removeItem(item);
}

void Game::setSelectedFrom(Cell *cell)
{
    goFrom = cell;
}

void Game::setSelectedTo(Cell *cell)
{
    goTo = cell;
}

Cell *Game::getSelectedFrom()
{
    return goFrom;
}

Cell *Game::getSelectedTo()
{
    return goTo;
}

QList<Piece *> Game::getWhiteTeam()
{
    return this->whiteTeam;
}

QList<Piece *> Game::getBlackTeam()
{
    return this->blackTeam;
}

