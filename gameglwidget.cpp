#include "gameglwidget.h"

GameGLWidget::GameGLWidget(QWidget *parent)
        : QGLWidget(parent) {}

void GameGLWidget::initializeGL()
{
    // Set up the rendering context, define display lists etc.:

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);

}

void GameGLWidget::resizeGL(int w, int h)
{
    // setup viewport, projection etc.:
    glViewport(0, 0, (GLint)w, (GLint)h);
}

void GameGLWidget::paintGL()
{
    glBegin(GL_QUADS);
    glEnd();
}
