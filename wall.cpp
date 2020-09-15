#include "wall.h"

int Wall::count = 0;

bool Wall::getGhost() const
{
    return ghost;
}

void Wall::setGhost(bool value)
{
    ghost = value;
}

Color Wall::getColor() const
{
    return color;
}

void Wall::setColor(const Color &value)
{
    color = value;
}

Wall::Wall(){}

Wall::Wall(QVector3D a, QVector3D b)
{
    *this = Wall(a, b, a, b);
}

Wall::Wall(QVector3D a, QVector3D b, QVector3D c, QVector3D d)
{
    voxels[0] = a;
    voxels[1] = b;
    voxels[2] = c;
    voxels[3] = d;

    count++;
    id = count;
    float deltaY = (voxels[0].y() - voxels[1].y());
    float deltaX = (voxels[0].x() - voxels[1].x());
    float result = qRadiansToDegrees(qAtan2(deltaY, deltaX));
    orientation = (result < 0) ? (360.0f + result) : result;
    distance = voxels[0].distanceToPoint(voxels[1]);
    ghost = false;
    visible = true;
    color = Color(1.0f, 1.0f, 1.0f);
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
