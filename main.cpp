#include <QCoreApplication>
#include <QApplication>
#include <QWidget>

#include "gameslist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget window;

    window.resize(300, 250);
    window.setWindowTitle("Simple example");
    window.show();



    return a.exec();
}
