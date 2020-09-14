#include "player.h"

QVector3D Player::getOldPosition() const
{
    return oldPosition;
}

void Player::setOldPosition(const QVector3D &value)
{
    oldPosition = value;
}

Player::Player(QVector3D position)
{
    this->position = position;
    orientation = 90.0f;
    speed = FULL_SPEED;
    speedModifier = FULL_SPEED;
}

float Player::getSpeedModifier() const
{
    return speedModifier;
}

void Player::setSpeedModifier(float value)
{
    speedModifier = value;
}

void Player::collisionSlot(const Wall *wall)
{
    if (wall->getGhost())
        return;

    position = oldPosition;
    float wo = wall->getOrientation();
    float po = orientation + direction;

    if (wall->getId() == collision)
        moveHeadingInner(wo, qCos(qDegreesToRadians(wo - po)), false);

    if (!wall->getGhost())
        collision = wall->getId();
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
    direction = degrees;
    moveHeadingInner(degrees, 1.0f, true);
}

void Player::moveHeadingInner(float degrees, float speedFactor, bool relative)
{
    float radians = qDegreesToRadians(((relative) ? orientation : 0) + degrees);
    float finalSpeed = speed * speedModifier * speedFactor;

    position.setX(position.x() + qCos(radians) * finalSpeed);
    position.setY(position.y() + qSin(radians) * finalSpeed);
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
