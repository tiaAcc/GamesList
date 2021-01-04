#include "gameslist.h"

#include <QMenu>
#include <QMenuBar>


GamesList::GamesList(QWidget* parent) : QMainWindow(parent)
{
    QAction *quit = new QAction("&Quit", this);
    QAction *open = new QAction("&Open", this);

    QMenu *file;
    file = menuBar()->addMenu("&File");

    file->addAction(open); // adding a file open button
    file->addSeparator();
    file->addAction(quit); // adding a program exit button

    connect(quit, &QAction::triggered, qApp, &QApplication::quit); // Выход из программы
    connect(open, &QAction::triggered, qApp, &QApplication::beep); // Заглушка под открытие базы данных

}
