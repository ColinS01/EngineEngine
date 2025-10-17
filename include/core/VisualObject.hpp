#ifndef VISUAL_OBJECT_HPP
#define VISUAL_OBJECT_HPP

#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <rend/Shader.h>

namespace Core {

class VisualObject {
public:
    VisualObject(glm::vec3 spawn_pos = glm::vec3(0.0f),
             glm::vec3 spawn_rot = glm::vec3(0.0f));
             
    virtual ~VisualObject();

    void upload();
    void drawVisualObject(bool drawVisualObject);

    void setShader(Shader* shader);

    void rotateVisualObject(glm::vec3 rot);

protected:
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    GLuint VAO, VBO, EBO;
    Shader* shader = nullptr;

    glm::vec3 current_pos;      // object position
    glm::vec3 current_rot;      // rotation in degrees: x=pitch, y=yaw, z=roll
};

} // namespace Core

#endif // VISUAL_OBJECT_HPP
