#include "gameslist.h"

#include <QMenu>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QString>


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

    QFrame *frame = new QFrame(this);

    setCentralWidget(frame);

    QVBoxLayout *vbox = new QVBoxLayout(frame);
    QVBoxLayout *vboxDown = new QVBoxLayout();

// Пробуем создать пользовательский QListWigetItem
/*
    QHBoxLayout *itemLayout = new QHBoxLayout();
    itemLayout->setSpacing(2);

    QLabel *ng = new QLabel("Game");
    QLabel *val = new QLabel("Value");
    QLabel *fin = new QLabel("finished");

    itemLayout->addWidget(ng);
    itemLayout->addWidget(val);
    itemLayout->addWidget(fin);

*/

    vbox->setSpacing(5);
    vboxDown->setSpacing(5);


    QListWidget *gameList = new QListWidget(frame);

    gameList->addItem("Doom");
    gameList->addItem("Cyberpunk 2077");
    gameList->addItem("The last of us 2");

    QPushButton *AddGameBtn = new QPushButton("Add", frame);

    QLineEdit *GameName = new QLineEdit(frame);
    GameName->setFixedWidth(300);
    QLineEdit *Value = new QLineEdit(frame);
    Value->setFixedWidth(300);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addRow("Name of a game:", GameName);
    formLayout->addRow("Value:", Value);

    vboxDown->addLayout(formLayout);
    vboxDown->addWidget(AddGameBtn);
    vboxDown->setAlignment(AddGameBtn ,Qt::AlignLeft);

    vbox->addSpacing(3);
    vbox->addWidget(gameList);
    vbox->addSpacing(20);
    vbox->addLayout(vboxDown);

    connect(quit, &QAction::triggered, qApp, &QApplication::quit); // Выход из программы
    connect(open, &QAction::triggered, qApp, &QApplication::beep); // Заглушка под открытие базы данных
}
