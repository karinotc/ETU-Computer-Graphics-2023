#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent), primitive(primitivesList.find("GL_POINTS")->second),
      alphaMode(alphaModeList.find("GL_ALWAYS")->second), scissorX(0), scissorY(0),
      alphaValue(0.0), sfactorMode(sfactorList.find("GL_ONE")->second),
      dfactorMode(dfactorList.find("GL_ZERO")->second) {
    coordinates = {
        { 0.5f,  0.6f},
        { 0.7f,  0.3f},
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
    glEnable(GL_SCISSOR_TEST);               //Тест отсечения
    glEnable(GL_ALPHA_TEST);                 //Тест прозрачности
    glEnable(GL_BLEND);                      //Тест смешивания цветов
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

void OpenGLWidget::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void OpenGLWidget::paintGL() {
    this->applyScissor();
    this->applyBlend();
    this->applyAlphaMode();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    this->drawPrimitive();
}

void OpenGLWidget::setPrimitiveType(const QString &type) {
    this->primitive = primitivesList.find(type)->second;
}

void OpenGLWidget::setAlphaMode(const QString &type) {
    this->alphaMode = alphaModeList.find(type)->second;
}

void OpenGLWidget::setAlphaValue(float value) {
    this->alphaValue = value;
}

void OpenGLWidget::drawPrimitive() {
    glLineWidth(5);
    glPointSize(5);

    glBegin(this->primitive);
        this->setPoints();
    glEnd();
}

void OpenGLWidget::setPoints() {
    for (int i = 0; i < this->coordinates.size(); i++) {
        glColor3d(this->colors[i][0], this->colors[i][1], this->colors[i][2]);
        glVertex2d(this->coordinates[i][0], this->coordinates[i][1]);
    }
}

void OpenGLWidget::applyScissor() {
    glScissor(this->scissorX, this->scissorY, OpenGLWidget::width()*2, OpenGLWidget::height()*2);
}

void OpenGLWidget::applyAlphaMode() {
    glAlphaFunc(this->alphaMode, this->alphaValue);
}

void OpenGLWidget::applyBlend() {
    glBlendFunc(this->sfactorMode, this->dfactorMode);
}

void OpenGLWidget::setScissorCoordinates(int x, int y) {
    this->scissorX = x;
    this->scissorY = y;
}

void OpenGLWidget::setSfactorMode(const QString &type) {
    this->sfactorMode = sfactorList.find(type)->second;
}

void OpenGLWidget::setDfactorMode(const QString &type) {
    this->dfactorMode = dfactorList.find(type)->second;
}
