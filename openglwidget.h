#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>
#include <vector>

#include "openglprimitives.h"
#include "openglaphamode.h"
#include "openglblendmode.h"

class OpenGLWidget : public QOpenGLWidget {
    Q_OBJECT

    //OpenGLAlphaMode alphaMode;
    //OpenGLSfactor sfactorMode;
    //OpenGLDfactor dfactorMode;
    GLenum primitive;
    GLenum alphaMode;
    GLenum sfactorMode;
    GLenum dfactorMode;
//    GLenum sfactorMode;
//    GLenum dfactorMode;
    std::vector<std::vector<float>> coordinates;
    std::vector<std::vector<float>> colors;
    int scissorX, scissorY;
    float alphaValue;
public:
    explicit OpenGLWidget(QWidget *parent = nullptr);
    void setPrimitiveType(const QString &type);
    void setAlphaMode(const QString &type);
    void setAlphaValue(float value);
    void setScissorCoordinates(int x, int y);
    void setSfactorMode(const QString &type);
    void setDfactorMode(const QString &type);
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
private:
    void drawPrimitive();
    void setPoints();
    void applyScissor();
    void applyAlphaMode();
    void applyBlend();
signals:

};

#endif // OPENGLWIDGET_H
