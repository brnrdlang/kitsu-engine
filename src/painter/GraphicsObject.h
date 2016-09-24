#ifndef KITSUNE_GRAPHICS_OBJECT_H
#define KITSUNE_GRAPHICS_OBJECT_H

#include <set>
#include <memory>

#include "SDL.h"
#include "SDL_rect.h"

class Scene;

struct Position {
    double x;
    double y;
    int z;

    Position(double x, double y) : x(x), y(y), z(0) {};
    Position(double x, double y, int z) : x(x), y(y), z(z) {};
};

class GraphicsObject {
public:
    GraphicsObject(SDL_Rect r) : hitbox_(r), pos_(r.x, r.y, 0), scene_(nullptr) {};
    GraphicsObject(SDL_Rect r, Position pos) : hitbox_(r), pos_(pos), scene_(nullptr) {};
    virtual ~GraphicsObject() {};

    friend bool operator<(const GraphicsObject& go1, const GraphicsObject& go2) {
        return go1.pos_.z > go2.pos_.z;
    };

    virtual void next(unsigned int time) {return;};

    virtual void draw() = 0;

    SDL_Rect hitbox_;
    Position pos_;
    Scene* scene_;
};

typedef std::unique_ptr<GraphicsObject> UniqueGObject_P;
typedef std::shared_ptr<GraphicsObject> SharedGObject_P;

struct compGOP {
    bool operator()(const SharedGObject_P& a, const SharedGObject_P & b) const {
        return *a < *b;
    }
};

typedef std::multiset<SharedGObject_P, compGOP> GOSet;
typedef std::multiset<SharedGObject_P, compGOP>::iterator ObjectID;

#endif
