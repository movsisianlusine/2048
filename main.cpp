#include "game_field.h"
#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    Game_field w;
    w.resize(600, 600);
    w.show();
    return a.exec();
}