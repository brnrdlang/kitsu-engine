#ifndef KITSUNE_GRAPHICS_OBJECT_H
#define KITSUNE_GRAPHICS_OBJECT_H

#include <vector>
#include <memory>

#include "SDL.h"
#include "SDL_rect.h"

class Scene;

struct Position {
    float x;
    float y;
    float z;

    Position(float x, float y) : x(x), y(y), z(0.0f) {};
    Position(float x, float y, float z) : x(x), y(y), z(z) {};
};

struct Color {
    float r;
    float g;
    float b;
    float a;

    Color(float c) : r(c), b(c), g(c), a(1.0f) {};
    Color(float c, float a) : r(c), b(c), g(c), a(a) {};
    Color(float r, float g, float b) : r(r), g(g), b(b), a(1.0f) {};
    Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {};
};

struct Vertex {
    Position p;
    Color c;

    Vertex(Position p, Color c) : p(p), c(c) {};
};

class GraphicsObject {
public:
    GraphicsObject() {};
    virtual ~GraphicsObject() {};

    virtual void draw() = 0;
};

typedef std::unique_ptr<GraphicsObject> UniqueGObject_P;
typedef std::shared_ptr<GraphicsObject> SharedGObject_P;

typedef std::vector<SharedGObject_P> GOArray;
typedef GOArray::iterator ObjectID;

#endif
