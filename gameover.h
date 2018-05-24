#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class Gameover;
}

class Gameover : public QDialog
{
    Q_OBJECT

public:
    explicit Gameover(QString winner, QWidget *parent = 0);
    ~Gameover();

private slots:
    void on_closeButton_clicked();

    //void on_playButton_clicked();

private:
    Ui::Gameover *ui;
};

#endif // GAMEOVER_H
