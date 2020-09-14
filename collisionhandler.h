#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <QVector3D>
#include "wall.h"
#include "player.h"
#include <QtDebug>

class CollisionHandler
{
public:
    CollisionHandler();
    static float distanceToWall(Player *player, const Wall *wall);
};

#endif // COLLISIONHANDLER_H
