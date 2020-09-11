#include "player.h"

float Player::getSpeedModifier() const
{
    return speedModifier;
}

void Player::setSpeedModifier(float value)
{
    speedModifier = value;
}

Player::Player(QVector3D position)
{
    this->position = position;
    this->orientation = 90.0f;
    this->speed = FULL_SPEED;
    this->speedModifier = FULL_SPEED;
}

QVector3D Player::getPosition() const
{
    return position;
}

float Player::getOrientation() const
{
    return orientation;
}

float Player::getSpeed() const
{
    return speed;
}

void Player::setSpeed(float speed)
{
    this->speed = speed;
}

void Player::setPosition(QVector3D position)
{
    this->position = position;
}

void Player::setOrientation(float orientation)
{
    this->orientation = orientation;
}

void Player::moveHeading(float degrees)
{
    float radians = qDegreesToRadians(orientation + degrees);
    float finalSpeed = speed * speedModifier;

    position.setX(position.x() + qCos(radians) * finalSpeed);
    position.setY(position.y() + qSin(radians) * finalSpeed);
}

void Player::moveHeadingAbsolute(float degrees, float speedFactor)
{


    qDebug() << degrees << speedFactor;
    float radians = qDegreesToRadians(degrees);

    position.setX(position.x() + qCos(radians) * speedFactor);
    position.setY(position.y() + qSin(radians) * speedFactor);
}

void Player::moveForward()
{
    moveHeading(0.0f);
}

void Player::moveBackward()
{
    moveHeading(180.0f);
}

void Player::moveLeft()
{
    moveHeading(90.0f);
}

void Player::moveRight()
{
    moveHeading(-90.0f);
}

void Player::turnLeft()
{
    orientation += 1.0f;
    if (orientation > 180.0f)
        orientation -= 360.0f;
}

void Player::turnRight()
{
    orientation -= 1.0f;
    if (orientation < -180.0f)
        orientation += 360.0f;
}
