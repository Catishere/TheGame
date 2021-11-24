#ifndef RENDER_H
#define RENDER_H

#include <GL/gl.h>
#include <QtOpenGL>
#include "screenposition.h"
#include "collisionhandler.h"
#include "controlshandler.h"
#include "player.h"

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 768

class Render
{
    scrPos upperLeft;
    scrPos upperRight;
    scrPos lowerLeft;
    scrPos lowerRight;
    scrPos center;
    Player *p;
    ControlsHandler *controls;
    float FOV = 60.0f; // horizontal FOV
    float VFOV = 60.0f; // vertical FOV

public:
    Render(ControlsHandler *controls);
    void paintCentralCircle();
    void paintInfo();
    void paintWalls();
    void paint3DWalls();
    void paintFOVLimit();
    inline float normalizeAngle(float angle);
    float getFOV() const;
    void setFOV(float value);
};

#endif // RENDER_H
