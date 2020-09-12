#include "wall.h"

int Wall::count = 0;

Wall::Wall()
{
}

Wall::Wall(QVector3D a, QVector3D b, QVector3D c, QVector3D d, bool visible)
{
    voxels[0] = a;
    voxels[1] = b;
    voxels[2] = c;
    voxels[3] = d;

    count++;
    id = count;
    this->visible = visible;
    float deltaY = (voxels[0].y() - voxels[1].y());
    float deltaX = (voxels[1].x() - voxels[0].x());
    float result = qRadiansToDegrees(qAtan2(deltaY, deltaX));
    orientation = (result < 0) ? (360.0f + result) : result;
    distance = voxels[0].distanceToPoint(voxels[1]);
}

bool Wall::getVisible() const
{
    return visible;
}

void Wall::setVisible(bool value)
{
    visible = value;
}

int Wall::getId() const
{
    return id;
}

void Wall::setId(int value)
{
    id = value;
}

float Wall::getDistance() const
{
    return distance;
}

float Wall::getOrientation() const
{
    return orientation;
}
