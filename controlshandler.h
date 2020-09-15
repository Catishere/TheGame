#ifndef CONTROLS_H
#define CONTROLS_H

#define PRESS_MODE true
#define RELEASE_MODE false

#include <QKeyEvent>
#include "player.h"
#include "wall.h"
#include <collisionhandler.h>
#include <QList>

class ControlsHandler : public QObject
{
    Q_OBJECT

public:
    ControlsHandler();
    void handleKeyEvent(QKeyEvent *keyEvent, bool mode);
    void movePlayer();

    Player *getPlayer() const;
    void setPlayer(Player *value);

    QList<Wall> getWalls() const;
    void setWalls(const QList<Wall> &value);

signals:
    void collision(const Wall *wall);

private:
    Player *player;
    QList<Wall> walls;
    bool forward;
    bool backward;
    bool left;
    bool right;
    bool lookLeft;
    bool lookRight;

    void populateWalls(QList<Wall> &walls);
};

#endif // CONTROLS_H
