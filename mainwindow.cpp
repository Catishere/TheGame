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
    render = new Render(controls);
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
    controls->movePlayer();
    Player *p = controls->getPlayer();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    render->paint3DWalls();
    glBegin(GL_LINES);

    render->paintFOVLimit();
    render->paintWalls();

    render->paintCentralCircle();
    paintInfo(p);
    glEnd();

    glFlush();
    this->update();
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

void MainWindow::resizeEvent(QResizeEvent *event)
{
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL();
}
