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
    spawnTeams();
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

QList<Piece *> Game::createTeam(Factory *factory)
{
    return factory->createTeam();
}

QString Game::getTurn()
{
    return turn;
}

void Game::checkVictory()
{
    bool hasKing = false;
    foreach(Piece * piece, whiteTeam){
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
    foreach (Cell * cell, cells){
        cell->removeFigure();
    }
    turn = "WHITE";
    spawnTeams();
}

void Game::spawnTeams()
{
    BlackFactory* blackFactory = new BlackFactory;
    blackTeam = createTeam(blackFactory);
    for(int i = 0; i < 16; i++){
        cells[i]->placeFigure(blackTeam.at(i));
    }
    WhiteFactory* whiteFactory = new WhiteFactory;
    whiteTeam = createTeam(whiteFactory);
    for(int i = 48; i < 64; i++){
        cells[i]->placeFigure(whiteTeam.at(i-48));
    }

    foreach (Piece* p, whiteTeam) {
        addToScene(p);
    }
    foreach (Piece* p, blackTeam) {
        addToScene(p);
    }
}

