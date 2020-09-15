#ifndef PLAYER_H
#define PLAYER_H

#define FULL_SPEED 1.0f
#define HALF_SPEED 0.707f
#define SPRINT_SPEED 1.4f
#define WALK_SPEED 0.3f

#include <QVector3D>
#include <QObject>
#include <QDebug>
#include <QtMath>
#include "wall.h"

class Player : public QObject
{
    Q_OBJECT

    QVector3D position;
    float orientation;
    float direction;
    float speed;
    float speedModifier;
    float FOV;
    QVector3D oldPosition;
    int collision = -1;

public:
    Player(QVector3D position);
    QVector3D getPosition() const;
    float getOrientation() const;
    void setPosition(QVector3D position);
    void setOrientation(float orientation);
    void moveHeading(float degrees);
    void moveHeadingInner(float degrees, float speedFactor, bool relative);
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void turnLeft();
    void turnRight();
    float getSpeed() const;
    void setSpeed(float speed);
    float getSpeedModifier() const;
    void setSpeedModifier(float value);

    QVector3D getOldPosition() const;
    void setOldPosition(const QVector3D &value);

public slots:
    void collisionSlot(const Wall *wall);
};

#endif // PLAYER_H
