#ifndef RENDEREDPOINT_H
#define RENDEREDPOINT_H


class RenderedPoint
{
public:
    RenderedPoint();
    RenderedPoint(float distance, float verticalAngle, float horizontalAngle);
    float getVerticalAngle() const;
    float getHorizontalAngle() const;
    float getDistance() const;
private:
    float distance;
    float verticalAngle;
    float horizontalAngle;
};

#endif // RENDEREDPOINT_H
