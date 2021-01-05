#include "gameslist.h"

#include <QMenu>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QPushButton>


GamesList::GamesList(QWidget* parent) : QMainWindow(parent)
{
    QAction *quit = new QAction("&Quit", this);
    QAction *open = new QAction("&Open", this);
    QAction *newFile = new QAction("&New File", this);


    quit->setShortcut(tr("CTRL+Q"));
    open->setShortcut(tr("CTRL+O"));
    newFile->setShortcut(tr("CTRL+N"));

    QMenu *file;
    file = menuBar()->addMenu("&File");

    file->addAction(newFile);   // adding a new file button
    file->addAction(open);      // adding a file open button
    file->addSeparator();
    file->addAction(quit);      // adding a program exit button

    QFrame *basic_frame = new QFrame(this);
    QFrame *frame_up = new QFrame(basic_frame);
    frame_up->setLineWidth(3);
    frame_up->setFrameShape(QFrame::Box);
    frame_up->setFrameShadow(QFrame::Sunken);
    QFrame *frame_down = new QFrame(basic_frame);
    frame_down->setLineWidth(3);
    frame_down->setFrameShape(QFrame::Box);
    frame_down->setFrameShadow(QFrame::Sunken);

    setCentralWidget(basic_frame);


    QVBoxLayout *vbox = new QVBoxLayout(basic_frame);
    vbox->setSpacing(5);
    QVBoxLayout *vbox_up = new QVBoxLayout(frame_up);
    vbox_up->setSpacing(2);
    QVBoxLayout *vbox_down = new QVBoxLayout(frame_down);
    vbox_up->setSpacing(2);

    QTextEdit *tedit = new QTextEdit(frame_up);
    QPushButton *btn = new QPushButton("Test", frame_down);


    vbox->addWidget(frame_up);
    vbox->addSpacing(5);
    vbox->addWidget(frame_down);
    vbox_up->addWidget(tedit);
    vbox_down->addWidget(btn);


    connect(quit, &QAction::triggered, qApp, &QApplication::quit); // Выход из программы
    connect(open, &QAction::triggered, qApp, &QApplication::beep); // Заглушка под открытие базы данных

}
