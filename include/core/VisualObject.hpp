#ifndef VISUAL_OBJECT_H
#define VISUAL_OBJECT_H

#include <glad/glad.h>
#include <vector>
#include <rend/Shader.h> // or wherever your Shader class lives

namespace Core {

class VisualObject {
public:
    VisualObject();
    virtual ~VisualObject();

    void upload();
    void drawVisualObject();
    void setShader(Shader* shader); // 🔹 new function

protected:
    unsigned int VAO, VBO, EBO;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    Shader* shader = nullptr; // 🔹 pointer to Shader object
};

} // namespace Core

#endif
