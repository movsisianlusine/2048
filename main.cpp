#include "game_field.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Game_field w;
    w.resize(400, 500);
    w.show();
    return a.exec();
}