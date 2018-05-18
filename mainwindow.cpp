#include "mainwindow.h"
#include "ui_mainwindow.h"

Game * game;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked()
{
    this->close();
}

void MainWindow::on_playButton_clicked()
{
    game = new Game();
    game->show();
    this->close();
}
