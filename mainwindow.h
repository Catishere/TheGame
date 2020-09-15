#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define SCREEN_WIDTH 768
#define SCREEN_HIGHT 768

#include <QMainWindow>
#include <QOpenGLWindow>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <GL/gl.h>
#include "render.h"
#include "screenposition.h"
#include "controlshandler.h"
#include <QTimer>

class MainWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:

    void startLoop();

    virtual void keyPressEvent(QKeyEvent *event);

    virtual void keyReleaseEvent(QKeyEvent *event);

    virtual void initializeGL();

    virtual void resizeGL(int w, int h);

    virtual void paintGL();

    void paintInfo(Player *p);

    void resizeEvent(QResizeEvent *event);

    void paintEvent(QPaintEvent *event);

private:
    QOpenGLContext *context;
    QOpenGLFunctions *openGLFunctions;
    ControlsHandler *controls;
    Render *render;
};
#endif // MAINWINDOW_H
