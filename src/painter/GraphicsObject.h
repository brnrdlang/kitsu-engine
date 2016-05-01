#ifndef KITSUNE_GRAPHICS_OBJECT_H
#define KITSUNE_GRAPHICS_OBJECT_H

#include "SDL.h"
#include "SDL_rect.h"

class SceneNode;

struct Position {
    double x;
    double y;
    int z;

    Position(double x, double y) : x(x), y(y), z(0) {};
    Position(double x, double y, int z) : x(x), y(y), z(z) {};
};

class GraphicsObject {
public:
    GraphicsObject(SDL_Rect r) : hitbox_(r), pos_(r.x, r.y, 0) {};
    GraphicsObject(SDL_Rect r, Position pos) : hitbox_(r), pos_(pos) {};
    virtual ~GraphicsObject() {};

    friend bool operator<(const GraphicsObject& go1, const GraphicsObject& go2) {
        return go1.pos_.z > go2.pos_.z;
    };

    virtual void next(unsigned int time) {return;};

    virtual void draw(SDL_Renderer* rndr) = 0;

    SDL_Rect hitbox_;
    Position pos_;
    SceneNode* node_;
};
#endif
