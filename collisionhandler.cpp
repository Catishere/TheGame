#include "collisionhandler.h"

CollisionHandler::CollisionHandler()
{

}

float CollisionHandler::distanceToWall(const Player *player, const Wall *wall)
{
    QVector3D pos = player->getPosition();
    float distanceP1 = pos.distanceToPoint(wall->voxels[2]);
    float distanceP2 = pos.distanceToPoint(wall->voxels[3]);
    float wallDistance = wall->getDistance();
    float p1Angle = (distanceP1 * distanceP1 - distanceP2 * distanceP2
            + wallDistance * wallDistance) / (2 * wallDistance * distanceP1);
    float p2Angle = (distanceP2 * distanceP2 - distanceP1 * distanceP1
            + wallDistance * wallDistance) / (2 * wallDistance * distanceP2);

    if (p1Angle < 0.0f)
        return distanceP1;
    else if (p2Angle < 0.0f)
        return distanceP2;
    else
        return pos.distanceToLine(wall->voxels[2],
                                (wall->voxels[2] - wall->voxels[3])
                                .normalized());
}
