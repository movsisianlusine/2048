#ifndef GAME_FIELD_H
#define GAME_FIELD_H
#include <QWidget>
#include <QGridLayout>
#include <QFrame>
#include <QVector>
#include <QLabel>
#include <QPushButton>

class Game_field : public QWidget
{
    Q_OBJECT;
public:
    explicit Game_field(QWidget *parent = nullptr);
    ~Game_field() = default;

private:
    void setup_ui();
    void setup_grid();
    QGridLayout *grid_layout;
    QVector<QFrame*> tiles;
    QLabel *score_label;
    QPushButton *undo_button;
};

#endif // GAME_FIELD_H