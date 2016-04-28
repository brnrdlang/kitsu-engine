#ifndef KITSUNE_GRAPHICS_OBJECT_H
#define KITSUNE_GRAPHICS_OBJECT_H

struct Position {
    double x;
    double y;
    int z;

    Position(double x, double y) : x(x), y(y), z(0) {};
    Position(double x, double y, int z) : x(x), y(y), z(z) {};
};

class GraphicsObject {
public:
    GraphicsObject;
    virtual ~GraphicsObject;

    virtual void draw() = 0;
    SDL_Rect hitbox_;
    Position pos_;
};

#endif
