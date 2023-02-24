#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent), primitive(primitivesList.find("GL_LINE_STRIPS")->second) {
    coordinates = {
        { 0.5f,  0.6f},
        { 0.8f,  0.1f},
        { 0.8f, -0.2f},
        { 0.6f, -0.5f},
        { 0.1f, -0.8f},
        {-0.6f, -0.7f},
        {-0.8f, -0.3f},
        {-0.7f,  0.2f},
        {-0.3f,  0.7f},
        { 0.0f,  0.9f}
    };

    colors = {
        {1.0f, 0.1f, 0.1f},
        {1.0f, 0.6f, 0.1f},
        {1.0f, 1.0f, 0.1f},
        {0.5f, 1.0f, 0.1f},
        {0.1f, 1.0f, 0.4f},
        {0.1f, 1.0f, 0.5f},
        {0.1f, 0.9f, 1.0f},
        {0.1f, 0.4f, 1.0f},
        {0.5f, 0.1f, 1.0f},
        {1.0f, 0.1f, 0.9f}
    };
}

void OpenGLWidget::initializeGL() {
    glClearColor(0.15f, 0.15f, 0.15f, 1.0f); //Цвет очистки цветовых буферов
    glEnable(GL_DEPTH_TEST);                 //Включение буфера глубины
    glEnable(GL_COLOR_MATERIAL);             //Отслеживание цвета материала
    glEnable(GL_LIGHT0);                     //Выбор нулевого источника света
    glEnable(GL_LIGHTING);                   //Включение освещения
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

void OpenGLWidget::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void OpenGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    this->drawPrimitive();
}

void OpenGLWidget::setPrimitiveType(const QString &type) {
    this->primitive = primitivesList.find(type)->second;
}

void OpenGLWidget::drawPrimitive() {
    glLineWidth(5);
    glPointSize(5);

    switch(this->primitive) {
    case OpenGLPrimitive::POLYGON:
        glBegin(GL_POLYGON);
            this->setPoints();
        glEnd();
        break;
    case OpenGLPrimitive::QUAD_STRIP:
        glBegin(GL_QUAD_STRIP);
            this->setPoints();
        glEnd();
        break;
    case OpenGLPrimitive::QUADS:
        glBegin(GL_QUADS);
            this->setPoints();
        glEnd();
        break;
    case OpenGLPrimitive::TRIANGLE_FAN:
        glBegin(GL_TRIANGLE_FAN);
            this->setPoints();
        glEnd();
        break;
    case OpenGLPrimitive::TRIANGLE_STRIP:
        glBegin(GL_TRIANGLE_STRIP);
            this->setPoints();
        glEnd();
        break;
    case OpenGLPrimitive::TRIANGLES:
        glBegin(GL_TRIANGLES);
            this->setPoints();
        glEnd();
        break;
    case OpenGLPrimitive::LINE_LOOP:
        glBegin(GL_LINE_LOOP);
            this->setPoints();
        glEnd();
        break;
    case OpenGLPrimitive::LINE_STRIPS:
        glBegin(GL_LINE_STRIP);
            this->setPoints();
        glEnd();
        break;
    case OpenGLPrimitive::LINES:
        glBegin(GL_LINES);
            this->setPoints();
        glEnd();
        break;
    case OpenGLPrimitive::POINTS:
        glBegin(GL_POINTS);
            this->setPoints();
        glEnd();
        break;
    default:
        break;
    }
}

void OpenGLWidget::setPoints() {
    for (int i = 0; i < this->coordinates.size(); i++) {
        glColor3d(this->colors[i][0], this->colors[i][1], this->colors[i][2]);
        glVertex2d(this->coordinates[i][0], this->coordinates[i][1]);
    }
}
