#include "game_field.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFrame>

// Layout
constexpr int MARGIN = 16;
constexpr int OUTER_SPACING = 12;
constexpr int GRID_MARGIN = 8;
constexpr int GRID_SPACING = 8;

// Sizes
constexpr int UNDO_BUTTON_HEIGHT = 48;
constexpr int SCORE_FONT_SIZE = 24;
constexpr int BUTTON_FONT_SIZE = 18;
constexpr int TILE_BORDER_RADIUS = 5;
constexpr int BUTTON_BORDER_RADIUS = 6;

// Colors
constexpr const char* COLOR_BACKGROUND = "#faf8ef";
constexpr const char* COLOR_TILE = "#cdc1b4";
constexpr const char* COLOR_BUTTON = "#8f7a66";
constexpr const char* COLOR_BUTTON_HOVER = "#9f8a76";
constexpr const char* COLOR_BUTTON_PRESSED = "#7f6a56";
constexpr const char* COLOR_BUTTON_TEXT = "white";
constexpr const char* COLOR_SCORE_TEXT = "#776e65";

Game_field::Game_field(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet(QString::fromStdString("background-color: " + std::string(COLOR_BACKGROUND) + ";"));
    setup_ui();
}

void Game_field::setup_ui() {
    QVBoxLayout *main_layout = new QVBoxLayout(this);
    main_layout->setContentsMargins(MARGIN, MARGIN, MARGIN, MARGIN);
    main_layout->setSpacing(OUTER_SPACING);

    score_label = new QLabel("Score: 0");
    score_label->setAlignment(Qt::AlignCenter);
    main_layout->addWidget(score_label);
    score_label->setStyleSheet(
        QString("font-size: %1px; font-weight: bold; color: %2;")
            .arg(SCORE_FONT_SIZE)
            .arg(COLOR_SCORE_TEXT)
        );

    QWidget *grid_container = new QWidget(this);
    grid_layout = new QGridLayout(grid_container);
    grid_layout->setSpacing(GRID_SPACING);
    grid_layout->setContentsMargins(GRID_MARGIN, GRID_MARGIN, GRID_MARGIN, GRID_MARGIN);
    setup_grid();
    main_layout->addWidget(grid_container, 1);

    undo_button = new QPushButton("Undo");
    undo_button->setFixedHeight(UNDO_BUTTON_HEIGHT);
    undo_button->setStyleSheet(
        QString("QPushButton { background-color: %1; color: %2;"
                "font-size: %3px; font-weight: bold; border-radius: %4px; }"
                "QPushButton:hover { background-color: %5; }"
                "QPushButton:pressed { background-color: %6; }")
            .arg(COLOR_BUTTON)
            .arg(COLOR_BUTTON_TEXT)
            .arg(BUTTON_FONT_SIZE)
            .arg(BUTTON_BORDER_RADIUS)
            .arg(COLOR_BUTTON_HOVER)
            .arg(COLOR_BUTTON_PRESSED)
        );
    main_layout->addWidget(undo_button);
}

void Game_field::setup_grid() {
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            QFrame *tile = new QFrame();
            tile->setStyleSheet(
                QString("background-color: %1; border-radius: %2px;")
                    .arg(COLOR_TILE)
                    .arg(TILE_BORDER_RADIUS)
                );
            tile->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            grid_layout->addWidget(tile, row, col);
            tiles.append(tile);
        }
        grid_layout->setRowStretch(row, 1);
        grid_layout->setColumnStretch(row, 1);
    }
}