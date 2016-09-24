#ifndef KITSUNE_PAINTER_SCENE_H
#define KITSUNE_PAINTER_SCENE_H

#include "GraphicsObject.h"

class Scene {
public:
    Scene() {};
    virtual ~Scene() {};

    virtual ObjectID insert(GraphicsObject* obj) = 0;
    virtual void remove(ObjectID id) = 0;

    virtual void drawall() = 0;
    virtual void drawall(ObjectID id) = 0;
    virtual void draw(ObjectID id) = 0;
};

class StandardScene : public Scene {
public:
    StandardScene(SDL_GLContext* context) : context_(context) {};
    virtual ~StandardScene() {};

    ObjectID insert(GraphicsObject* obj) {
        obj->scene_ = this;

        return scene_objects.insert(UniqueGObject_P(obj));
    };

    void remove(ObjectID id) {
        scene_objects.erase(id);
    };

    void drawall() {
        for (auto& obj_p : scene_objects) {
            obj_p->draw();
        }
    };

    void drawall(ObjectID id) {
        for( auto it = id; it != scene_objects.end(); ++it) {
            (*it)->draw();
        }
    };

    void draw(ObjectID id) {
        (*id)->draw();
    };

    SDL_GLContext* context_;
private:
    GOSet scene_objects;
};

#endif
