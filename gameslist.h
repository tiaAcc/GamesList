#ifndef GAMESLIST_H
#define GAMESLIST_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>


class GamesList : public QMainWindow
{

Q_OBJECT

public:
    GamesList(QWidget *parent = nullptr);
};

#endif // GAMESLIST_H
