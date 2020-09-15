#include "controlshandler.h"

ControlsHandler::ControlsHandler(){
    forward = RELEASE_MODE;
    backward = RELEASE_MODE;
    left = RELEASE_MODE;
    right = RELEASE_MODE;
    lookLeft = RELEASE_MODE;
    lookRight = RELEASE_MODE;
    player = new Player(QVector3D(10, 10, 50));
    populateWalls(walls);
    QObject::connect(this, &ControlsHandler::collision,
                     player, &Player::collisionSlot);
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

void ControlsHandler::movePlayer()
{
    player->setOldPosition(player->getPosition());
    float criticalDistance = 50.1f;

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
      float distance = CollisionHandler::distanceToWall(player,
                                                        &wall);
      if (distance < criticalDistance)
      {
        qDebug() << wall.getId() << wall.getOrientation();
        emit collision(&wall);
      }
    }
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

void ControlsHandler::populateWalls(QList<Wall> &walls)
{

    walls.append(Wall(QVector3D(0, 100, 100),
                      QVector3D(0, 200, 100),
                      QVector3D(0, 200, 0),
                      QVector3D(0, 100, 0)));
    walls.append(Wall(QVector3D(0, 200, 100),
                      QVector3D(100, 200, 100),
                      QVector3D(100, 200, 0),
                      QVector3D(0, 200, 0)));
    walls.append(Wall(QVector3D(100, 200, 100),
                      QVector3D(200, 300, 100),
                      QVector3D(200, 300, 0),
                      QVector3D(100, 200, 0)));
    // start box
    walls.append(Wall(QVector3D(25, 25, 25),
                      QVector3D(25, 75, 25),
                      QVector3D(25, 75, 0),
                      QVector3D(25, 25, 0)));
    walls.last().setColor(Color(0.7, 0.0f, 0.0f));

    walls.append(Wall(QVector3D(25, 25, 25),
                      QVector3D(75, 25, 25),
                      QVector3D(75, 25, 0),
                      QVector3D(25, 25, 0)));
    walls.last().setColor(Color(0.7, 0.0f, 0.0f));

    walls.append(Wall(QVector3D(75, 75, 25),
                      QVector3D(75, 25, 25),
                      QVector3D(75, 25, 0),
                      QVector3D(75, 75, 0)));
    walls.last().setColor(Color(0.7, 0.0f, 0.0f));

    walls.append(Wall(QVector3D(75, 75, 25),
                      QVector3D(25, 75, 25),
                      QVector3D(25, 75, 0),
                      QVector3D(75, 75, 0)));
    walls.last().setColor(Color(0.7, 0.0f, 0.0f));

    walls.append(Wall(QVector3D(25, 25, 25),
                      QVector3D(25, 75, 25),
                      QVector3D(75, 75, 25),
                      QVector3D(75, 25, 25)));
    walls.last().setColor(Color(0.7, 0.0f, 0.0f));
    walls.last().setGhost(true);

    LINE(walls, 300, 300, 310, 300);
    LINE(walls, 310, 300, 320, 305);
    LINE(walls, 320, 305, 320, 340);

    LINE(walls, 300, 350, 330, 370);
    walls.last().setGhost(true);

    LINE(walls, 330, 420, 330, 370);
    LINE(walls, 340, 420, 330, 420);
    LINE(walls, 340, 410, 340, 420);
    LINE(walls, 370, 410, 340, 410);
    LINE(walls, 370, 420, 370, 410);
    LINE(walls, 380, 420, 370, 420);
    LINE(walls, 380, 370, 380, 420);
    LINE(walls, 350, 350, 380, 370);

    LINE(walls, 310, 300, 310, 340);
    LINE(walls, 310, 340, 340, 340);
    LINE(walls, 340, 340, 340, 300);
    LINE(walls, 340, 300, 350, 300);
    LINE(walls, 350, 300, 350, 350);
    LINE(walls, 350, 350, 300, 350);
    LINE(walls, 300, 350, 300, 300);


    LINE(walls, 330, 370, 380, 370);

    LINE(walls, 380, 420, 390, 415);
    LINE(walls, 390, 415, 390, 325);
    LINE(walls, 390, 325, 380, 320);
    LINE(walls, 380, 320, 370, 320);
    LINE(walls, 370, 320, 370, 346);


    LINE(walls, 350, 300, 360, 305);
    LINE(walls, 360, 305, 360, 340);
    LINE(walls, 360, 340, 380, 352);
    LINE(walls, 380, 352, 380, 320);


    LINE(walls, 340, 420, 350, 415);
    LINE(walls, 350, 415, 350, 410);

    LINE(walls, 330, 340, 330, 320);
    LINE(walls, 330, 320, 340, 320);

}
