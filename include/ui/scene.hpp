#pragma once

namespace ui {

class Camera;
class Light;

class Scene {
public:
    Scene();
    ~Scene();

    // primary functions
    void update(float dt);
    void render();

    // APIs to set/get environment parameters, add/remove features, etc.
    void setBackgroundColor(float r, float g, float b);
    void setAmbientLight(float intensity);
    void addObject(char obj_type);
    void removeObject(int obj_id);

private:
    float backgroundColor[3];
    float ambientLight;
};

}
