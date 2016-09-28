#include <iostream>

#include "Shapes.h"

const GLchar* vertexSource = 
R"VERTSH(#version 150

in vec2 position;

void main()
{
    gl_Position = vec4(position, 0.0f, 1.0f);
})VERTSH";

const GLchar* fragmentSource =
R"FRAGSH(#version 150

uniform vec3 triangleColor;

out vec4 outColor;

void main()
{
    outColor = vec4(triangleColor, 1.0);
})FRAGSH";

Triangle::Triangle() : color_(1.0f) {
    float vertices_[]  ={
        0.0f, 0.5f,
        0.5f, -0.5f,
        -0.5f, -0.5f
    };

    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_), vertices_, GL_STATIC_DRAW);

    vert_sh_ = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert_sh_, 1, &vertexSource, NULL);
    frag_sh_ = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag_sh_, 1, &fragmentSource, NULL);

    glCompileShader(vert_sh_);
    glCompileShader(frag_sh_);

    sh_program_ = glCreateProgram();
    glAttachShader(sh_program_, vert_sh_);
    glAttachShader(sh_program_, frag_sh_);

    glLinkProgram(sh_program_);
    glUseProgram(sh_program_);

    GLint posAttrib = glGetAttribLocation(sh_program_, "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(posAttrib);

    uni_ = glGetUniformLocation(sh_program_, "triangleColor");
}

Triangle::~Triangle() {
    glDeleteProgram(sh_program_);
    glDeleteShader(frag_sh_);
    glDeleteShader(vert_sh_);

    glDeleteBuffers(1, &vbo_);

    glDeleteVertexArrays(1, &vao_);
}

void Triangle::draw() {
    glBindVertexArray(vao_);

    glUniform3f(uni_, color_, 0.0f, 0.0f);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}
