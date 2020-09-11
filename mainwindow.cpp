#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QOpenGLWindow()
{
    setSurfaceType(QWindow::OpenGLSurface);
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2,1);
    setFormat(format);
    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);
    openGLFunctions = context->functions();
    controls = new ControlsHandler();
    distance = 0.0f;
    spin = 0.0f;
}

MainWindow::~MainWindow()
{
}

void MainWindow::startLoop()
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::paintGL);
    timer->start();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    controls->handleKeyEvent(event, PRESS_MODE);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    controls->handleKeyEvent(event, RELEASE_MODE);
}

void MainWindow::initializeGL()
{
}

void MainWindow::resizeGL(int w, int h)
{
}

void MainWindow::paintGL()
{
    RenderedPoint * rp = controls->calculatePositionOffset().getPoints();
    Player *p = controls->getPlayer();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    float ploriRad = qDegreesToRadians(p->getOrientation());
    float leftHalfCos = 0.5f * qCos(ploriRad - qDegreesToRadians(30.0f));
    float leftHalfSin = 0.5f * qSin(ploriRad - qDegreesToRadians(30.0f));

    float rightHalfCos = 0.5f * qCos(ploriRad + qDegreesToRadians(30.0f));
    float rightHalfSin = 0.5f * qSin(ploriRad + qDegreesToRadians(30.0f));

    glVertex2f(0.0, 0.0);
    glVertex2f(leftHalfCos, leftHalfSin);

    glVertex2f(leftHalfCos, leftHalfSin);
    glVertex2f(rightHalfCos, rightHalfSin);

    glVertex2f(rightHalfCos, rightHalfSin);
    glVertex2f(0.0, 0.0);

    Wall wall;
    foreach (wall, controls->getWalls()) {

        // render
        const QVector3D *v = wall.voxels;
        float p1xdelta = v[2].x() - p->getPosition().x();
        float p1ydelta = v[2].y() - p->getPosition().y();

        float p2xdelta = v[3].x() - p->getPosition().x();
        float p2ydelta = v[3].y() - p->getPosition().y();

        float p1x = p1xdelta / 200;
        float p1y = p1ydelta / 200;
        float p2x = p2xdelta / 200;
        float p2y = p2ydelta / 200;

        glVertex2f(p1x, p1y);
        glVertex2f(p2x, p2y);
    }

    glEnd();

    paintCentralCircle();
    paintInfo(p);

    glFlush();
    this->update();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
}

void MainWindow::paintCentralCircle()
{
    glBegin(GL_LINE_LOOP);
         for(int i = 0; i <= 300; i++)
         {
             double angle = 2 * M_PI * i / 300;
             double x = qCos(angle)/ 200;
             double y = qSin(angle)/ 200;
             glVertex2d(x,y);
         }
    glEnd();
}

void MainWindow::paintInfo(Player *p)
{
    QVector3D pos = p->getPosition();
    QString str = QString("X: %1, Y: %2, Z: %3, Angle: %4")
            .arg(qRound(pos.x()))
            .arg(qRound(pos.y()))
            .arg(qRound(pos.z()))
            .arg(qRound(p->getOrientation()));

    QPainter painter(this);
    painter.setPen(Qt::white);
    painter.setFont(QFont("Arial", 11));
    painter.drawText(0, 0, width(), height()
                     , Qt::AlignTop, str);
    painter.end();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL();
}