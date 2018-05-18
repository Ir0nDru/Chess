#-------------------------------------------------
#
# Project created by QtCreator 2018-02-04T21:06:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    piece.cpp \
    game.cpp \
    board.cpp \
    cell.cpp \
    pawn.cpp \
    knight.cpp \
    rook.cpp \
    bishop.cpp \
    king.cpp \
    queen.cpp

HEADERS  += mainwindow.h \
    piece.h \
    game.h \
    board.h \
    cell.h \
    pawn.h \
    knight.h \
    rook.h \
    bishop.h \
    king.h \
    queen.h

FORMS    += mainwindow.ui

RESOURCES += \
    img.qrc
