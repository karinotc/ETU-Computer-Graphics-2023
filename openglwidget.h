#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>
#include <vector>

#include "openglprimitives.h"

class OpenGLWidget : public QOpenGLWidget {
    Q_OBJECT

    OpenGLPrimitive primitive;
    std::vector<std::vector<float>> coordinates;
    std::vector<std::vector<float>> colors;
public:
    explicit OpenGLWidget(QWidget *parent = nullptr);
    void setPrimitiveType(const QString &type);
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
private:
    void draw();
    void setPoints();
signals:

};

#endif // OPENGLWIDGET_H
