#include "wall.h"

Wall::Wall()
{
}

Wall::Wall(QVector3D a, QVector3D b, QVector3D c, QVector3D d)
{
    voxels[0] = a;
    voxels[1] = b;
    voxels[2] = c;
    voxels[3] = d;

    float deltaY = (voxels[0].x() - voxels[1].y());
    float deltaX = (voxels[1].x() - voxels[0].x());
    float result = qRadiansToDegrees(qAtan2(deltaY, deltaX));
    orientation = (result < 0) ? (360.0f + result) : result;
    distance = voxels[0].distanceToPoint(voxels[1]);
}

float Wall::getDistance() const
{
    return distance;
}

float Wall::getOrientation() const
{
    return orientation;
}
