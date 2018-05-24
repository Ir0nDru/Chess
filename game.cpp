#include "game.h"
#include <QDesktopWidget>
#include <iostream>

bool Cell::waitingTurn = false;

Game::Game()
{
    goFrom = NULL;
    turn = "WHITE";

    setFocusPolicy(Qt::StrongFocus);
    setFixedSize(740, 740);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 740, 740);
    //Draw field
    QGraphicsRectItem * borderOuter = new QGraphicsRectItem();
    QGraphicsRectItem * borderInner = new QGraphicsRectItem();

    borderOuter->setRect(0,0,740,740);
    borderOuter->setBrush(QBrush(QColor::fromRgb(55, 20, 10)));
    borderInner->setRect(50,50,640,640);
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
        letters[i]->setPos(75 + 80*i, 695);
        letters[i]->setZValue(1);
        addToScene(letters[i]);
    }

    QGraphicsTextItem * nums[8];
    for (int i=0; i<8; i++){
        nums[i] = new QGraphicsTextItem();
        nums[i]->setFont(QFont("times", 20));
        nums[i]->setDefaultTextColor(QColor::fromRgb(180, 170, 0));
        nums[i]->setPlainText(QString::number(8 - i));
        nums[i]->setPos(15, 70 + 80*i);
        addToScene(nums[i]);
    }

    turnTable = new QGraphicsTextItem();
    turnTable->setFont(QFont("times", 20));
    turnTable->setDefaultTextColor(QColor::fromRgb(255, 255, 255));
    turnTable->setPlainText(QString("TURN: " + turn));
    turnTable->setPos(50,10);
    addToScene(turnTable);

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

Cell *Game::getSelectedFrom()
{
    return goFrom;
}

QList<Piece *> Game::getWhiteTeam()
{
    return this->whiteTeam;
}

QList<Piece *> Game::getBlackTeam()
{
    return this->blackTeam;
}

QString Game::getTurn()
{
    return turn;
}

void Game::checkVictory()
{
    bool hasKing = false;
    foreach(Piece * piece, whiteTeam){
        qDebug() << piece->type();
        if (piece->type() == King::Type){
            hasKing = true;
        }
    }
    if(!hasKing){
        qDebug() << "white lost";
        gameover();
        //break;
    }
    hasKing = false;
    foreach(Piece * piece, blackTeam){
        qDebug() << piece->type();
        if (piece->type() == King::Type){
            hasKing = true;
        }
    }
    if(!hasKing){
        qDebug() << "black lost";
        gameover();
    }
}

void Game::changeTurn()
{
    if (turn == "WHITE"){
        turn = "BLACK";
        turnTable->setDefaultTextColor(QColor::fromRgb(0, 0, 0));
    }
    else{
        turn = "WHITE";
        turnTable->setDefaultTextColor(QColor::fromRgb(255, 255, 255));
    }
    turnTable->setPlainText(QString("TURN: " + turn));
}

void Game::gameover()
{
    //piece of shit
//    foreach(Piece * piece, blackTeam){
//        delete piece;
//    }
//    foreach(Piece * piece, whiteTeam){
//        delete piece;
//    }
//    //delete goFrom;
//    foreach (Cell * cell, cells) {
//        delete cell;
//    }
//    delete scene;
//    Gameover * window = new Gameover(turn);
//    window->show();
//    //delete this;
}

