#ifndef KITSUNE_PAINTER_SCENETREE_H
#define KITSUNE_PAINTER_SCENETREE_H

#include <set>
#include "SDL_timer.h"
#include "GraphicsObject.h"

struct compGOP {
    bool operator()(const GraphicsObject * const & a, const GraphicsObject * const & b) const {
        return *a < *b;
    }
};

class SceneNode {
public:
    SceneNode(SceneNode* parent, SDL_Rect rect);
    virtual ~SceneNode();

    void insert(GraphicsObject* obj);
    void remove(GraphicsObject* obj);
    void draw(SDL_Renderer* rndr, std::set<GraphicsObject*, compGOP>* draw_set);

    SDL_Rect hitbox_;
private:
    std::set<GraphicsObject*, compGOP> sprites_;
    SceneNode* parent_;
    SceneNode* children_[4];
};

class AnimationEvent {
public:
    AnimationEvent(unsigned int time, GraphicsObject* sprite) : time_(time), sprite_(sprite) {};
    virtual ~AnimationEvent() {};

    AnimationEvent(const AnimationEvent &ev) : time_(ev.time_), sprite_(ev.sprite_) {};
    AnimationEvent(AnimationEvent &&ev) : time_(ev.time_), sprite_(ev.sprite_) {};

    AnimationEvent& operator=(const AnimationEvent &ev) {
        this->time_ = ev.time_;
        this->sprite_ = ev.sprite_;

        return *this;
    }

    AnimationEvent& operator=(AnimationEvent &&ev) {
        this->time_ = ev.time_;
        this->sprite_ = ev.sprite_;

        return *this;
    }

    friend bool operator<(const AnimationEvent& ev1, const AnimationEvent& ev2) {
        return ev1.time_ < ev2.time_;
    };
    friend bool operator>(const AnimationEvent ev1, const AnimationEvent& ev2) {
        return ev1.time_ > ev2.time_;
    };

    unsigned int time_;
    GraphicsObject* sprite_;
};

int quadrant(SDL_Rect& A, SDL_Rect& B);
#endif
