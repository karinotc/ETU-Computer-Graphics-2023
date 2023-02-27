#ifndef OPENGLAPHAMODE_H
#define OPENGLAPHAMODE_H

#include<QString>
#include <QtOpenGL>
#include<unordered_map>

const std::unordered_map<QString, unsigned int> alphaModeList = {
  {"GL_NEVER", GL_NEVER},
  {"GL_LESS", GL_LESS},
  {"GL_EQUAL", GL_EQUAL},
  {"GL_LEQUAL", GL_LEQUAL},
  {"GL_GREATER", GL_GREATER},
  {"GL_NOTEQUAL", GL_NOTEQUAL},
  {"GL_GEQUAL", GL_GEQUAL},
  {"GL_ALWAYS", GL_ALWAYS}
};

#endif // OPENGLAPHAMODE_H
