#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(593, 390);
    w.setWindowTitle("JOGO DA MATEMÁTICA");
    w.show();
    return a.exec();
}
