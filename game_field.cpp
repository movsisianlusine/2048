#include "game_field.h"
#include <QGridLayout>
#include <QFrame>

Game_field::Game_field(QWidget *parent)
    : QWidget(parent)
{
    setupGrid();
}


void Game_field::setupGrid() {
    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(5);

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QFrame *tile = new QFrame(this);

            tile->setStyleSheet("background-color: #cdc1b4; border-radius: 5px;");
            tile->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

            gridLayout->addWidget(tile, row, col);

            tiles.append(tile);
        }
        gridLayout->setRowStretch(row, 1);
        gridLayout->setColumnStretch(row, 1);
    }
}