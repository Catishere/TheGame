#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <QVector3D>
#include "wall.h"

class CollisionHandler
{
public:
    CollisionHandler();
    static float distanceToWall(const QVector3D player, const Wall *wall);
};

#endif // COLLISIONHANDLER_H
