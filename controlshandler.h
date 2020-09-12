#ifndef CONTROLS_H
#define CONTROLS_H

#define PRESS_MODE true
#define RELEASE_MODE false

#include <QKeyEvent>
#include "player.h"
#include "wall.h"
#include <collisionhandler.h>
#include <render.h>
#include <QList>

class ControlsHandler : public QObject
{
    Q_OBJECT

public:
    ControlsHandler();
    void handleKeyEvent(QKeyEvent *keyEvent, bool mode);
    RenderedWall calculatePositionOffset();

    Player *getPlayer() const;
    void setPlayer(Player *value);

    QList<Wall> getWalls() const;
    void setWalls(const QList<Wall> &value);

signals:
    void collision(const Wall *wall);

private:
    Player *player;
    QList<Wall> walls;
    Render render;
    bool forward;
    bool backward;
    bool left;
    bool right;
    bool lookLeft;
    bool lookRight;
};

#endif // CONTROLS_H
