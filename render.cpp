#include "render.h"

Render::Render(ControlsHandler *controls)
{
    upperLeft.xOffset = -0.75f;
    upperLeft.yOffset = 0.75f;
    upperLeft.scale = 0.75f;

    upperRight.xOffset = 0.70f;
    upperRight.yOffset = 0.70f;
    upperRight.scale = 0.85f;

    lowerLeft.xOffset = -0.75f;
    lowerLeft.yOffset = -0.75f;
    lowerLeft.scale = 0.5f;

    lowerRight.xOffset = 0.75f;
    lowerRight.yOffset = -0.75f;
    lowerRight.scale = 0.75f;

    center.xOffset = 0.0f;
    center.yOffset = 0.0f;
    center.scale = 1.0f;

    this->p = controls->getPlayer();
    this->controls = controls;
}


float Render::getFOV() const
{
    return FOV;
}

void Render::setFOV(float value)
{
    FOV = value;
}

void Render::paintCentralCircle()
{
    glBegin(GL_LINE_LOOP);
         for(int i = 0; i <= 300; i++)
         {
             double angle = 2 * M_PI * i / 300;
             double x = qCos(angle)/ 200;
             double y = qSin(angle)/ 200;
             glVertex2f(x, y);
         }
    glEnd();
}

void Render::paintWalls()
{
    QVector3D playerPos = p->getPosition();
    Wall wall;
    foreach (wall, controls->getWalls()) {
        if (!wall.getVisible())
            continue;
        // render
        const QVector3D *v = wall.voxels;
        float p1xdelta = v[2].x() - playerPos.x();
        float p1ydelta = v[2].y() - playerPos.y();

        float p2xdelta = v[3].x() - playerPos.x();
        float p2ydelta = v[3].y() - playerPos.y();

        float p1x = p1xdelta / 200;
        float p1y = p1ydelta / 200;
        float p2x = p2xdelta / 200;
        float p2y = p2ydelta / 200;

        glVertex2f(p1x, p1y);
        glVertex2f(p2x, p2y);
    }
}

void Render::paint3DWalls()
{
    QVector3D playerPos = p->getPosition();
    float playerOri = p->getOrientation();
    float halfFOV = FOV / 2;
    float halfVFOV = VFOV / 2;

    Wall wall;
    foreach (wall, controls->getWalls()) {
        float distance = CollisionHandler::distanceToWall(p, &wall);
        float color = 1 - distance / 655.0f;
        if (!wall.getVisible())
            continue;

        Color wc = wall.getColor();
        // render
        glColor3f(color * wc.getRed(), color * wc.getBlue(), color * wc.getBlue());
        glBegin(GL_QUADS);
        const QVector3D *v = wall.voxels;
        for (int i = 0; i < 4; ++i) {
            float deltax = v[i].x() - playerPos.x();
            float deltay = v[i].y() - playerPos.y();
            float deltaz = v[i].z() - playerPos.z();
            float deltaxy = qSqrt(deltax * deltax + deltay * deltay);
            float absoluteAngle = qRadiansToDegrees(qAtan2(deltay, deltax));
            float absoluteAngleVert = qRadiansToDegrees(qAtan2(deltaz,deltaxy));
            float relativeAngle = normalizeAngle(absoluteAngle - playerOri);
            glVertex2f(-relativeAngle / halfFOV, absoluteAngleVert / halfVFOV);
        }

        glEnd();
        glColor3f(1, 1, 1);
    }
}

void Render::paintFOVLimit()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    float halfFOV = FOV/2;
    float ploriRad = qDegreesToRadians(p->getOrientation());
    float leftHalfCos = 0.5f * qCos(ploriRad - qDegreesToRadians(halfFOV));
    float leftHalfSin = 0.5f * qSin(ploriRad - qDegreesToRadians(halfFOV));

    float rightHalfCos = 0.5f * qCos(ploriRad + qDegreesToRadians(halfFOV));
    float rightHalfSin = 0.5f * qSin(ploriRad + qDegreesToRadians(halfFOV));

    glVertex2f(0.0, 0.0);
    glVertex2f(leftHalfCos, leftHalfSin);

    glVertex2f(leftHalfCos, leftHalfSin);
    glVertex2f(rightHalfCos, rightHalfSin);

    glVertex2f(rightHalfCos, rightHalfSin);
    glVertex2f(0.0, 0.0);
    glColor3f(1, 1, 1);
}

float Render::normalizeAngle(float angle)
{
    if (angle > 180.0f)
        return angle - 360;
    else if (angle < -180.0f)
        return 360 + angle;
    else return angle;
}
