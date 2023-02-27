#ifndef OPENGLBLENDMODE_H
#define OPENGLBLENDMODE_H

#include<QString>
#include<unordered_map>

const std::unordered_map<QString, unsigned int> sfactorList = {
    {"GL_ZERO", GL_ZERO},
    {"GL_ONE", GL_ONE},
    {"GL_DST_COLOR", GL_DST_COLOR},
    {"GL_ONE_MINUS_DST_COLOR", GL_ONE_MINUS_DST_COLOR},
    {"GL_SRC_ALPHA", GL_SRC_ALPHA},
    {"GL_ONE_MINUS_SRC_ALPHA", GL_ONE_MINUS_SRC_ALPHA},
    {"GL_ALPHA", GL_ALPHA},
    {"GL_ONE_MINUS_DST_ALPHA", GL_ONE_MINUS_DST_ALPHA},
    {"GL_SRC_ALPHA_SATURATE", GL_SRC_ALPHA_SATURATE}
};

const std::unordered_map<QString, unsigned int> dfactorList = {
    {"GL_ZERO", GL_ZERO},
    {"GL_ONE", GL_ONE},
    {"GL_SRC_COLOR", GL_SRC_COLOR},
    {"GL_ONE_MINUS_SRC_COLOR", GL_ONE_MINUS_SRC_COLOR},
    {"GL_SRC_ALPHA", GL_SRC_ALPHA},
    {"GL_ONE_MINUS_SRC_COLOR", GL_ONE_MINUS_SRC_COLOR},
    {"GL_DST_ALPHA", GL_DST_ALPHA},
    {"GL_ONE_MINUS_DST_ALPHA", GL_ONE_MINUS_DST_ALPHA}
};

#endif // OPENGLBLENDMODE_H
