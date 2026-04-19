#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <QWidget>
#include <QGridLayout>
#include <QFrame>
#include <QVector>

class Game_field : public QWidget
{
    Q_OBJECT

public:
    explicit Game_field(QWidget *parent = nullptr);
    ~Game_field() = default;

private:
    void setupGrid();

    QGridLayout *gridLayout;
    QVector<QFrame*> tiles;
};

#endif // GAME_FIELD_H