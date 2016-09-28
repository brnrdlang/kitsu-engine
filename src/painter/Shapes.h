#ifndef KITSUNE_SHAPES_H
#define KITSUNE_SHAPES_H

#include <vector>

#include <GL/glew.h>

#include "GraphicsObject.h"

class Triangle : public GraphicsObject {
public:
    Triangle();
    virtual ~Triangle();

    void draw();

    float color_;
private:
    GLuint vbo_;
    GLuint vao_;
    GLuint sh_program_;
    GLuint vert_sh_;
    GLuint frag_sh_;

    GLint uni_;
};

#endif
