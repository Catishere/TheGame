#ifndef RENDEREDWALL_H
#define RENDEREDWALL_H

#include <renderedpoint.h>

class RenderedWall
{
public:
    RenderedWall();
    RenderedWall(RenderedPoint *points);
    void setPoint(int number, const RenderedPoint point);
    RenderedPoint* getPoints();
private:
    RenderedPoint points[4];
};

#endif // RENDEREDWALL_H
