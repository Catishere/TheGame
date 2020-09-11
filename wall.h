#ifndef WALL_H
#define WALL_H

#include <QVector3D>
#include <QtMath>

class Wall
{
    float orientation;
    float distance;
public:
    Wall();
    Wall(QVector3D a, QVector3D b, QVector3D c, QVector3D d);
    QVector3D voxels[4];
    float getDistance() const;
    float getOrientation() const;
};

#endif // WALL_H
