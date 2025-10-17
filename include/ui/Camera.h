#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace ui
{
    class Camera
    {
    public:
        Camera()
        {
            position = glm::vec3(0.0f, 0.0f, -3.0f);
            target = glm::vec3(0.0f, 0.0f, 0.0f);
            up = glm::vec3(0.0f, 1.0f, 0.0f);

            view = glm::lookAt(position, target, up);
        }

        ~Camera() = default;

        glm::mat4 getViewMatrix() const { return view; }
        glm::vec3 getPosition() const { return position; }

    private:
        glm::vec3 position;
        glm::vec3 target;
        glm::vec3 up;
        glm::mat4 view;
    };
}

#endif // CAMERA_H
