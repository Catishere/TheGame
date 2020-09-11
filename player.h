#ifndef PLAYER_H
#define PLAYER_H

#define FULL_SPEED 1.0f
#define HALF_SPEED 0.707f
#define SPRINT_SPEED 1.4f
#define WALK_SPEED 0.3f

#include <QVector3D>
#include <QDebug>
#include <QtMath>

class Player
{
    QVector3D position;
    float orientation;
    float speed;
    float speedModifier;

public:
    Player(QVector3D position);
    QVector3D getPosition() const;
    float getOrientation() const;
    void setPosition(QVector3D position);
    void setOrientation(float orientation);
    void moveHeading(float degrees);
    void moveHeadingAbsolute(float degrees, float speedFactor);
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
};

#endif // PLAYER_H
