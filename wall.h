#ifndef WALL_H
#define WALL_H

#define LINE(list, x1, y1, x2, y2) \
    list.append(Wall(QVector3D(x1, y1, 0), QVector3D(x2, y2, 0)));

#include <QVector3D>
#include <QtMath>


class Wall
{
    float orientation;
    float distance;
    int id;
    bool visible;
    bool ghost;
    static int count;
public:
    Wall();
    Wall(QVector3D a, QVector3D b);
    Wall(QVector3D a, QVector3D b, QVector3D c, QVector3D d);
    QVector3D voxels[4];
    float getDistance() const;
    float getOrientation() const;
    int getId() const;
    void setId(int value);
    bool getVisible() const;
    void setVisible(bool value);
    bool getGhost() const;
    void setGhost(bool value);
};

#endif // WALL_H
