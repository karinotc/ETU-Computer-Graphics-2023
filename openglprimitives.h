#ifndef OPENGLPRIMITIVES_H
#define OPENGLPRIMITIVES_H

#include<QString>
#include<unordered_map>

enum class OpenGLPrimitive {
    POINTS,
    LINES,
    LINE_STRIPS,
    LINE_LOOP,
    TRIANGLES,
    TRIANGLE_STRIP,
    TRIANGLE_FAN,
    QUADS,
    QUAD_STRIP,
    POLYGON
};

const std::unordered_map<QString, OpenGLPrimitive> primitivesList = {
    {"GL_POLYGON", OpenGLPrimitive::POLYGON},
    {"GL_QUAD_STRIP", OpenGLPrimitive::QUAD_STRIP},
    {"GL_QUADS", OpenGLPrimitive::QUADS},
    {"GL_TRIANGLE_FAN", OpenGLPrimitive::TRIANGLE_FAN},
    {"GL_TRIANGLE_STRIP", OpenGLPrimitive::TRIANGLE_STRIP},
    {"GL_TRIANGLES", OpenGLPrimitive::TRIANGLES},
    {"GL_LINE_LOOP", OpenGLPrimitive::LINE_LOOP},
    {"GL_LINE_STRIPS", OpenGLPrimitive::LINE_STRIPS},
    {"GL_LINES", OpenGLPrimitive::LINES},
    {"GL_POINTS", OpenGLPrimitive::POINTS}
};

#endif // OPENGLPRIMITIVES_H
