#include "renderedpoint.h"

RenderedPoint::RenderedPoint()
{

}

float RenderedPoint::getVerticalAngle() const
{
    return verticalAngle;
}

float RenderedPoint::getHorizontalAngle() const
{
    return horizontalAngle;
}

RenderedPoint::RenderedPoint(float distance, float verticalAngle, float horizontalAngle)
{
    this->distance = distance;
    this->verticalAngle = verticalAngle;
    this->horizontalAngle = horizontalAngle;
}

float RenderedPoint::getDistance() const
{
    return distance;
}
