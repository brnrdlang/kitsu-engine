#include "SceneTree.h"

SceneNode::SceneNode(SceneNode* parent, SDL_Rect rect) : nw_(nullptr), ne_(nullptr), se_(nullptr), sw_(nullptr), front_(nullptr), back_(nullptr), parent_(parent), hitbox_(rect) {}

void SceneNode::draw() {
    if (this->back_ != nullptr) {
        this->back_->draw();
    }
    if (this->nw_ != nullptr) {
        this->nw_->draw();
    }
    if (this->ne_ != nullptr) {
        this->ne_->draw();
    }
    if (this->se_ != nullptr) {
        this->se_->draw();
    }
    if (this->sw_ != nullptr) {
        this->sw->draw();
    }
    for(auto obj : sprites) {
        obj.draw();
    }
}

SceneTree::SceneTree() {}

unsigned int SceneTree::next_event_time() {
    return queue_.top().time_;
}

void SceneTree::draw_all(unsigned int time) {
    while (next_event_time() <= time) {
        queue_.top().draw();
        queue_.pop();
    }
}
