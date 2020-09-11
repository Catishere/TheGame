#include "render.h"

Render::Render()
{
}

RenderedWall Render::renderWall(const Player *player, const Wall *wall)
{
    RenderedWall rw;

    for (int i = 0; i < 4; i++)
    {
        rw.setPoint(i, renderPoint(player, &wall->voxels[i]));
    }
    return rw;
}

RenderedPoint Render::renderPoint(const Player *player,
                                  const QVector3D *ap) const
{
    QVector3D bp = player->getPosition();
    float distance = bp.distanceToPoint(*ap);

    QVector3D cp(ap->x(), ap->y(), bp.z());
    QVector3D dp(ap->x(), bp.y(), bp.z());

    QVector3D v1(ap->x() - bp.x(), ap->y() - bp.y(), ap->z() - bp.z());
    QVector3D v2(cp.x() - bp.x(), cp.y() - bp.y(), cp.z() - bp.z());
    QVector3D v3(dp.x() - bp.x(), dp.y() - bp.y(), dp.z() - bp.z());
    float verticalAngle = qAcos(v1.normalized().x() * v2.normalized().x()
                      + v1.normalized().y() * v2.normalized().y()
                      + v1.normalized().z() * v2.normalized().z());
    float horizontalAngle = qAcos(v2.normalized().x() * v3.normalized().x()
                      + v2.normalized().y() * v3.normalized().y()
                      + v2.normalized().z() * v3.normalized().z());

    return RenderedPoint(distance, verticalAngle / VFOV,
                         horizontalAngle + qDegreesToRadians(player->getOrientation()) / HFOV);
}
