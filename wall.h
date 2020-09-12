#ifndef WALL_H
#define WALL_H

#include <QVector3D>
#include <QtMath>

class Wall
{
    float orientation;
    float distance;
    int id;
    bool visible;
    static int count;
public:
    Wall();
    Wall(QVector3D a, QVector3D b, QVector3D c, QVector3D d, bool visible);
    QVector3D voxels[4];
    float getDistance() const;
    float getOrientation() const;
    int getId() const;
    void setId(int value);
    bool getVisible() const;
    void setVisible(bool value);
};

#endif // WALL_H
