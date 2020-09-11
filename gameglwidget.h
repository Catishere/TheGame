#ifndef GAMEGLWIDGET_H
#define GAMEGLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL>

class GameGLWidget : public QGLWidget
{
    Q_OBJECT        // must include this if you use Qt signals/slots
public:
    GameGLWidget(QWidget *parent);

protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

};
#endif // GAMEGLWIDGET_H
