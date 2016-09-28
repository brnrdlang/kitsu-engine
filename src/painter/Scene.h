#ifndef KITSUNE_PAINTER_SCENE_H
#define KITSUNE_PAINTER_SCENE_H

#include "GL/glew.h"
#include "GraphicsObject.h"

class Scene {
public:
    Scene() {};
    virtual ~Scene() {};

    virtual ObjectID add(GraphicsObject* obj) = 0;
    virtual void remove(ObjectID id) = 0;

    virtual void drawall() = 0;
    virtual void drawall(ObjectID id) = 0;
    virtual void draw(ObjectID id) = 0;
};

class StandardScene : public Scene {
public:
    StandardScene() {};
    virtual ~StandardScene() {};

    ObjectID add(GraphicsObject* obj) {
        return scene_objects.insert(scene_objects.end(), SharedGObject_P(obj));
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

private:
    GOArray scene_objects;
};

#endif
