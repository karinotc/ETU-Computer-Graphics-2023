#ifndef OPENGLPRIMITIVES_H
#define OPENGLPRIMITIVES_H

#include<QString>
#include <QtOpenGL>
#include<unordered_map>

const std::unordered_map<QString, unsigned int> primitivesList = {
    {"GL_POLYGON", GL_POLYGON},
    {"GL_QUAD_STRIP", GL_QUAD_STRIP},
    {"GL_QUADS", GL_QUADS},
    {"GL_TRIANGLE_FAN", GL_TRIANGLE_FAN},
    {"GL_TRIANGLE_STRIP", GL_TRIANGLE_STRIP},
    {"GL_TRIANGLES", GL_TRIANGLES},
    {"GL_LINE_LOOP", GL_LINE_LOOP},
    {"GL_LINE_STRIPS", GL_LINE_STRIP},
    {"GL_LINES", GL_LINES},
    {"GL_POINTS", GL_POINTS}
};

#endif // OPENGLPRIMITIVES_H
