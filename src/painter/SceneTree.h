#ifndef KITSUNE_PAINTER_SCENETREE_H
#define KITSUNE_PAINTER_SCENETREE_H

#include <list>
#include <priority_queue>
#include <functional>
#include "SDL_timer.h"

class SceneNode {
public:
    SceneNode(SceneNode* parent, SDL_Rect rect);
    virtual ~SceneNode();

    void draw();

    std::list<GraphicsObject> sprites;
private:
    SceneNode* parent_;
    SceneNode* nw_;
    SceneNode* ne_;
    SceneNode* se_;
    SceneNode* sw_;

    SceneNode* front_;
    SceneNode* back_;

    SDL_Rect hitbox_;
};

class AnimationEvent {
public:
    AnimationEvent(unsigned int time, SceneNode* sprite) : time_(time), sprite_(sprite) {};
    virtual ~AnimationEvent() {};

    bool operator<(AnimationEvent& ev) {
        return this->time_ < ev.time_;
    };
    bool operator>(AnimationEvent& ev) {
        return this->time_ > ev.time_;
    };

    const unsigned int time_;
    const SceneNode* sprite_;
};

class SceneTree {
public:
    SceneTree() {};
    virtual ~SceneTree() {};

    void draw_all(unsigned int time);
    unsigned int next_event_time();
private:
    SceneNode root_;
    std::priority_queue<AnimationEvent, std::vector<AnimationEvent>, std::greater<AnimationEvent>> queue_;
};

#endif
