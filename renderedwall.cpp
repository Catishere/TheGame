#include "renderedwall.h"

RenderedWall::RenderedWall()
{}

RenderedWall::RenderedWall(RenderedPoint *points)
{
    for (int i = 0; i < 4; i++)
    {
        this->points[i] = points[i];
    }
}

void RenderedWall::setPoint(int number, const RenderedPoint point)
{
    this->points[number] = point;
}

RenderedPoint *RenderedWall::getPoints()
{
    return points;
}
