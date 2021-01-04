#include <QCoreApplication>
#include <QApplication>
#include <QWidget>

#include "gameslist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    GamesList window;

    window.resize(300, 250);
    window.show();

    return a.exec();
}
