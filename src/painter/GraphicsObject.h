#ifndef KITSUNE_GRAPHICS_OBJECT_H
#define KITSUNE_GRAPHICS_OBJECT_H

#include "SDL.h"
#include "SDL_rect.h"

struct Position {
    double x;
    double y;
    int z;

    Position(double x, double y) : x(x), y(y), z(0) {};
    Position(double x, double y, int z) : x(x), y(y), z(z) {};
};

struct Color {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;

    Color(Uint8 r, Uint8 g, Uint8 b) : r(r), g(g), b(b), a(255) {};
    Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) : r(r) g(g), b(b), a(a) {};

    Uint32 to_SDL(SDL_Surface* s) {
        return SDL_MapRGBA(s->format, r, g, b, a);
    }
};

class GraphicsObject {
public:
    GraphicsObject();
    virtual ~GraphicsObject() {};

    friend bool operator<(const GraphicsObject& go1, const GraphicsObject& go2) {
        return go1.pos_.z > go2.pos_.z;
    };

    virtual void draw(SDL_Surface* surf) = 0;
    SDL_Rect hitbox_;
    Position pos_;
};
#endif
