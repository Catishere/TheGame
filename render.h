#ifndef RENDER_H
#define RENDER_H

#include <player.h>
#include <wall.h>
#include <renderedwall.h>
#include <renderedpoint.h>
#include <QtMath>
#include <QVector3D>

class Render
{
    const float VFOV = 0.785398;
    const float HFOV = 1.309;

public:
    Render();
    RenderedWall renderWall(const Player *player, const Wall *wall);
    RenderedPoint renderPoint(const Player *player, const QVector3D *point) const;
};

#endif // RENDER_H
