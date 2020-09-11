#include "controlshandler.h"

ControlsHandler::ControlsHandler(){
    forward = RELEASE_MODE;
    backward = RELEASE_MODE;
    left = RELEASE_MODE;
    right = RELEASE_MODE;
    lookLeft = RELEASE_MODE;
    lookRight = RELEASE_MODE;
    player = new Player(QVector3D(10, 10, 0));
    walls.append(Wall(QVector3D(0, 100, 100),
                      QVector3D(0, 200, 100),
                      QVector3D(0, 200, 0),
                      QVector3D(0, 100, 0)));

    walls.append(Wall(QVector3D(0, 200, 100),
                      QVector3D(100, 200, 100),
                      QVector3D(100, 200, 0),
                      QVector3D(0, 200, 0)));
}

void ControlsHandler::handleKeyEvent(QKeyEvent *keyEvent, bool mode)
{
    Qt::KeyboardModifiers modifiers = keyEvent->modifiers();

    if (modifiers.testFlag(Qt::ShiftModifier))
        player->setSpeedModifier(SPRINT_SPEED);
    else if (modifiers.testFlag(Qt::ControlModifier))
        player->setSpeedModifier(WALK_SPEED);
    else
        player->setSpeedModifier(FULL_SPEED);

    switch (keyEvent->key())
    {
        case Qt::Key_W:
            forward = mode;
        break;
        case Qt::Key_S:
            backward = mode;
        break;
        case Qt::Key_A:
            left = mode;
        break;
        case Qt::Key_D:
            right = mode;
        break;
        case Qt::Key_Q:
            lookLeft = mode;
        break;
        case Qt::Key_E:
            lookRight = mode;
        break;
    }
}

RenderedWall ControlsHandler::calculatePositionOffset()
{
    QVector3D oldPos = player->getPosition();

    if (forward + backward + left + right >= 2)
        player->setSpeed(HALF_SPEED);
    else
        player->setSpeed(FULL_SPEED);

    if (forward)
        player->moveForward();
    if (backward)
        player->moveBackward();
    if (left)
        player->moveLeft();
    if (right)
        player->moveRight();
    if (lookLeft)
        player->turnLeft();
    if (lookRight)
        player->turnRight();


    //collision

    foreach (const Wall &wall, walls)
    {
        if (collisionHandler.distanceToWall(player->getPosition(), &wall) < 2.0f)
        {
            player->setPosition(oldPos);
//            float wo = wall.getOrientation();
//            float po = player->getOrientation();
//            player->moveHeadingAbsolute(wo, -qSin(po));
        }
    }

    return render.renderWall(player, &(walls.at(0)));
}

Player *ControlsHandler::getPlayer() const
{
    return player;
}

void ControlsHandler::setPlayer(Player *player)
{
    this->player = player;
}

QList<Wall> ControlsHandler::getWalls() const
{
    return walls;
}

void ControlsHandler::setWalls(const QList<Wall> &value)
{
    this->walls = value;
}
